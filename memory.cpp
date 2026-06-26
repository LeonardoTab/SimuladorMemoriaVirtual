#include <iostream>
#include "memory.h"

// Construtor
Memory::Memory() {

    proximoFrame = 0;

    for (int i = 0; i < QUANTIDADE_FRAMES; i++) {

        frames.push_back(Frame(i));
    }
}

// Mostra o estado atual da memória física
void Memory::mostrarFrames() {

    std::cout << "\n";
    std::cout << "=========================================\n";
    std::cout << " ESTADO DA MEMORIA FISICA\n";
    std::cout << "=========================================\n";

    for (const Frame &frame : frames) {

        std::cout << "Frame "
                  << frame.numero
                  << " -> ";

        if(frame.ocupado)
            std::cout << "Pagina " << frame.pagina;
        else
            std::cout << "Livre";

        std::cout << std::endl;
    }

    std::cout << "=========================================\n";
}
