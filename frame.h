#ifndef FRAME_H
#define FRAME_H

class Frame {

public:

    // Número do frame
    int numero;

    // Indica se o frame está ocupado
    bool ocupado;

    // Página armazenada neste frame
    int pagina;

    // Construtor
    Frame(int numero);

};

#endif
