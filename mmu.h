#ifndef MMU_H
#define MMU_H

#include <vector>
#include "memory.h"
#include "process.h"

class MMU {

private:

    // Referência para a memória física
    Memory &memoria;

    // Processos registrados
    std::vector<Process*> processos;

    // Estatísticas
    int acessos;
    int pageFaults;
    int hits;

public:

    // Construtor
    MMU(Memory &memoria);

    // Registra processo
    void adicionarProcesso(Process &processo);

    // Acesso à memória
    void acessar(Process &processo, int enderecoVirtual);

    // Exibe estatísticas
    void mostrarEstatisticas();

};

#endif
