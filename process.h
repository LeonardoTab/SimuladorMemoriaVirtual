#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <vector>
#include "page.h"

class Process {

public:

    // Nome do processo
    std::string nome;

    // Tamanho do processo (em KB)
    int tamanho;

    // Vetor de páginas do processo
    std::vector<Page> paginas;

    // Construtor
    Process(std::string nome, int tamanho);

};

#endif
