#include "process.h"

// Construtor do processo
Process::Process(std::string nome, int tamanho) {

    this->nome = nome;
    this->tamanho = tamanho;

    // Cada página possui 8 KB
    int quantidadePaginas = (tamanho + 7) / 8;

    // Cria todas as páginas do processo
    for (int i = 0; i < quantidadePaginas; i++) {
        paginas.push_back(Page(i));
    }
}
