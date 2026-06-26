#include <iostream>

#include "memory.h"
#include "process.h"
#include "mmu.h"

using namespace std;

int main() {

    cout << "=========================================\n";
    cout << " SIMULADOR DE MEMORIA VIRTUAL\n";
    cout << "=========================================\n";

    Memory memoria;
    MMU mmu(memoria);

    // Dois processos leves
    Process processo1("Processo_A", 96);
    Process processo2("Processo_B", 48);

    mmu.adicionarProcesso(processo1);
    mmu.adicionarProcesso(processo2);

    cout << "\n=========== PROCESSO A ===========\n";

    for(int i = 0; i < 12; i++) {
        mmu.acessar(processo1, i * 8);
    }

    cout << "\n=========== PROCESSO B ===========\n";

    mmu.acessar(processo2, 0);
    mmu.acessar(processo2, 8);
    mmu.acessar(processo2, 16);

    memoria.mostrarFrames();

    mmu.mostrarEstatisticas();

    return 0;
}
