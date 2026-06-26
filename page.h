#ifndef PAGE_H
#define PAGE_H

class Page {

public:

    // Número da página virtual
    int numero;

    // Indica se a página está carregada na memória física
    bool presente;

    // Número do frame onde a página está carregada
    int frame;

    // Bit de referência
    bool referenciada;

    // Bit de modificação (Dirty Bit)
    bool modificada;

    // Construtor
    Page(int numero);

};

#endif
