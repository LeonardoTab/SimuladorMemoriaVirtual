#include "frame.h"

// Construtor do frame
Frame::Frame(int numero) {

    this->numero = numero;

    // Inicialmente o frame está livre
    ocupado = false;

    // Nenhuma página armazenada
    pagina = -1;
}
