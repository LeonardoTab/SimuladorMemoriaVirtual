# Simulador de Memória Virtual

Projeto desenvolvido para a disciplina **Análise e Aplicação de Sistemas Operacionais** da **Universidade do Vale do Rio dos Sinos (UNISINOS)**.

---

## Objetivo

Este projeto implementa um simulador de gerenciamento de memória virtual utilizando paginação. O sistema simula o funcionamento de uma Unidade de Gerenciamento de Memória (MMU), realizando a tradução de endereços virtuais para endereços físicos, tratamento de Page Fault e substituição de páginas utilizando o algoritmo FIFO (First In, First Out).

---

## Especificações do Sistema

| Componente | Valor |
|------------|------:|
| Memória Virtual | 1 MB |
| Memória Física | 64 KB |
| Tamanho da Página | 8 KB |
| Tamanho do Frame | 8 KB |
| Quantidade de Frames | 8 |
| Algoritmo de Substituição | FIFO |

---

## Funcionalidades Implementadas

- Simulação de memória virtual e memória física.
- Implementação da MMU (Memory Management Unit).
- Tradução de endereços virtuais para físicos.
- Implementação da tabela de páginas.
- Tratamento de Page Fault.
- Carregamento de páginas na memória principal.
- Substituição de páginas utilizando FIFO.
- Simulação de dois processos leves.
- Exibição do estado final da memória física.
- Estatísticas da execução (acessos, hits e page faults).

---

## Estrutura do Projeto

```text
.
├── main.cpp
├── frame.cpp
├── frame.h
├── memory.cpp
├── memory.h
├── mmu.cpp
├── mmu.h
├── page.cpp
├── page.h
├── process.cpp
├── process.h
└── README.md
```

---

## Compilação

```bash
g++ *.cpp -o simulador
```

---

## Execução

```bash
./simulador
```

---

## Funcionamento

Durante a execução o simulador apresenta:

- Processo que realizou o acesso;
- Endereço virtual solicitado;
- Página e offset correspondentes;
- Tradução realizada pela MMU;
- Ocorrência de Page Fault;
- Carregamento de páginas em frames livres;
- Substituição de páginas utilizando FIFO;
- Estado final da memória física;
- Estatísticas da execução.

---

## Conceitos Aplicados

- Sistemas Operacionais
- Gerenciamento de Memória
- Memória Virtual
- Memória Física
- Paginação
- MMU
- Tradução de Endereços
- Tabela de Páginas
- Page Fault
- Algoritmo FIFO

---

## Autor

**Leonardo Taborda**

Universidade do Vale do Rio dos Sinos (UNISINOS)

Disciplina: Análise e Aplicação de Sistemas Operacionais
