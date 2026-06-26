#include "page.h"

// Construtor da página
Page::Page(int numero) {

    this->numero = numero;

    // Inicialmente a página não está na memória
    presente = false;

    // Nenhum frame associado
    frame = -1;

    // Bits inicialmente desligados
    referenciada = false;
    modificada = false;
}
