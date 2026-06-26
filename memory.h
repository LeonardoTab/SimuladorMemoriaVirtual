#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include "frame.h"

class Memory {

public:

    // Memória virtual (KB)
    static const int MEMORIA_VIRTUAL = 1024;

    // Memória física (KB)
    static const int MEMORIA_FISICA = 64;

    // Página / Frame (KB)
    static const int TAMANHO_PAGINA = 8;

    // Quantidade de frames
    static const int QUANTIDADE_FRAMES = MEMORIA_FISICA / TAMANHO_PAGINA;

    // Frames da memória física
    std::vector<Frame> frames;

    // Próximo frame do FIFO
    int proximoFrame;

    // Construtor
    Memory();

    // Exibe o estado da memória física
    void mostrarFrames();

};

#endif
