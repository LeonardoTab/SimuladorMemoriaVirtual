#include <iostream>
#include <iomanip>
#include "mmu.h"

// Construtor
MMU::MMU(Memory &memoria) : memoria(memoria) {

    acessos = 0;
    pageFaults = 0;
    hits = 0;
}

// Registra processo
void MMU::adicionarProcesso(Process &processo) {

    processos.push_back(&processo);
}

// Simula acesso à memória
void MMU::acessar(Process &processo, int enderecoVirtual) {

    acessos++;

    int pagina = enderecoVirtual / Memory::TAMANHO_PAGINA;
    int offset = enderecoVirtual % Memory::TAMANHO_PAGINA;

    std::cout << "\n========== ACESSO ==========\n";
    std::cout << "Processo: " << processo.nome << std::endl;
    std::cout << "Endereco Virtual: " << enderecoVirtual << " KB\n";
    std::cout << "Pagina: " << pagina << std::endl;
    std::cout << "Offset: " << offset << " KB\n";

    if (pagina >= processo.paginas.size()) {

        std::cout << "Endereco invalido.\n";
        return;
    }

    if (!processo.paginas[pagina].presente) {

        pageFaults++;

        std::cout << "PAGE FAULT!\n";

        bool carregou = false;

        // Procura frame livre
        for (Frame &frame : memoria.frames) {

            if (!frame.ocupado) {

                frame.ocupado = true;
                frame.pagina = pagina;

                processo.paginas[pagina].presente = true;
                processo.paginas[pagina].frame = frame.numero;

                std::cout << "Pagina " << pagina
                          << " carregada no Frame "
                          << frame.numero << std::endl;

                carregou = true;
                break;
            }
        }

        // FIFO
        if (!carregou) {

            Frame &frame = memoria.frames[memoria.proximoFrame];

            int paginaRemovida = frame.pagina;

            for (Process *p : processos) {

                if (paginaRemovida < p->paginas.size() &&
                    p->paginas[paginaRemovida].presente &&
                    p->paginas[paginaRemovida].frame == frame.numero) {

                    p->paginas[paginaRemovida].presente = false;
                    p->paginas[paginaRemovida].frame = -1;
                }
            }

            std::cout << "FIFO: Pagina "
                      << paginaRemovida
                      << " removida do Frame "
                      << frame.numero << std::endl;

            frame.pagina = pagina;

            processo.paginas[pagina].presente = true;
            processo.paginas[pagina].frame = frame.numero;

            std::cout << "FIFO: Pagina "
                      << pagina
                      << " carregada no Frame "
                      << frame.numero << std::endl;

            memoria.proximoFrame++;

            if (memoria.proximoFrame >= Memory::QUANTIDADE_FRAMES)
                memoria.proximoFrame = 0;
        }

    } else {

        hits++;

        std::cout << "Pagina ja esta carregada na memoria.\n";
    }

    std::cout << "Frame: "
              << processo.paginas[pagina].frame
              << std::endl;
}

// Estatísticas
void MMU::mostrarEstatisticas() {

    std::cout << "\n=========================================\n";
    std::cout << " ESTATISTICAS DA EXECUCAO\n";
    std::cout << "=========================================\n";

    std::cout << "Acessos...........: " << acessos << std::endl;
    std::cout << "Page Faults.......: " << pageFaults << std::endl;
    std::cout << "Hits..............: " << hits << std::endl;

    double taxaHit = acessos ? (100.0 * hits / acessos) : 0;
    double taxaFault = acessos ? (100.0 * pageFaults / acessos) : 0;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Taxa de Hit.......: " << taxaHit << "%\n";
    std::cout << "Taxa de Fault.....: " << taxaFault << "%\n";

    std::cout << "=========================================\n";
}
