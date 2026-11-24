#ifndef FILMES_H
#define FILMES_H

#include <stddef.h>

#define MAX_FILMES 100


struct filmes {
    int codigo;
    char nome[100];
    char genero[50];
    int ano;
    float nota;
};

void inicializarCatalogo(struct filmes *catalogo[]);
void cadastrarFilme(struct filmes *catalogo[]);
void listarFilmes(struct filmes *catalogo[]);
void buscarFilme(struct filmes *catalogo[]);
void gerarRelatorios(struct filmes *catalogo[]);
void salvarCatalogo(struct filmes *catalogo[]);
void carregarCatalogo(struct filmes *catalogo[]);
void liberarCatalogo(struct filmes *catalogo[]);

#endif