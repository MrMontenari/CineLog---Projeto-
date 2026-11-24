#include "filmes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarCatalogo(struct filmes *catalogo[]){
    for(int i = 0; i < MAX_FILMES; i++){
        catalogo[i] = NULL;
    }
}

void cadastrarFilme(struct filmes *catalogo[]) {

    int i;

    for (i = 0; i < MAX_FILMES; i++) {
        if (catalogo[i] == NULL) {
            break;
        }
    }

    if (i == MAX_FILMES) {
        printf("Catalogo cheio!\n");
        return;
    }

    catalogo[i] = malloc(sizeof(struct filmes));

    if (catalogo[i] == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    printf("\nCodigo: ");
    scanf("%d", &catalogo[i]->codigo);

    getchar();

    printf("Nome: ");
    fgets(catalogo[i]->nome, 100, stdin);
    catalogo[i]->nome[strcspn(catalogo[i]->nome, "\n")] = '\0';

    printf("Genero: ");
    fgets(catalogo[i]->genero, 50, stdin);
    catalogo[i]->genero[strcspn(catalogo[i]->genero, "\n")] = '\0';

    printf("Ano: ");
    scanf("%d", &catalogo[i]->ano);

    printf("Nota: ");
    scanf("%f", &catalogo[i]->nota);

    printf("\nFilme cadastrado com sucesso!\n");
}


void listarFilmes(struct filmes *catalogo[]) {

    int encontrou = 0;

    for (int i = 0; i < MAX_FILMES; i++) {

        if (catalogo[i] != NULL) {

            printf("\nCodigo: %d", catalogo[i]->codigo);
            printf("\nNome: %s", catalogo[i]->nome);
            printf("\nGenero: %s", catalogo[i]->genero);
            printf("\nAno: %d", catalogo[i]->ano);
            printf("\nNota: %.1f\n", catalogo[i]->nota);

            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("\nCatalogo vazio!\n");
    }
}

void buscarFilme(struct filmes *catalogo[]) {
    int codigo;
    int encontrou = 0;

    printf("\nDigite o codigo do filme: ");
    scanf("%d", &codigo);

    for (int i = 0; i < MAX_FILMES; i++) {

        if (catalogo[i] != NULL && catalogo[i]->codigo == codigo) {

            printf("\n===== FILME ENCONTRADO =====\n");
            printf("Codigo: %d\n", catalogo[i]->codigo);
            printf("Nome: %s\n", catalogo[i]->nome);
            printf("Genero: %s\n", catalogo[i]->genero);
            printf("Ano: %d\n", catalogo[i]->ano);
            printf("Nota: %.1f\n", catalogo[i]->nota);

            encontrou = 1;
            break;
        }
    }

    if (encontrou == 0) {
        printf("\nFilme nao encontrado!\n");
    }
}

void gerarRelatorios(struct filmes *catalogo[]) {

    int quantidade = 0;
    float soma = 0;
    struct filmes *melhorFilme = NULL;

    for (int i = 0; i < MAX_FILMES; i++) {

        if (catalogo[i] != NULL) {

            quantidade++;
            soma += catalogo[i]->nota;

            if (melhorFilme == NULL ||
                catalogo[i]->nota > melhorFilme->nota) {

                melhorFilme = catalogo[i];
            }
        }
    }

    if (quantidade == 0) {
        printf("\nNenhum filme cadastrado para gerar relatorios.\n");
        return;
    }

    printf("\n===== RELATORIOS CINELOG =====\n");

    printf("\nQuantidade de filmes: %d\n", quantidade);

    printf("Media das notas: %.2f\n", soma / quantidade);

    printf("\n===== FILME COM MAIOR NOTA =====\n");
    printf("Nome: %s\n", melhorFilme->nome);
    printf("Nota: %.1f\n", melhorFilme->nota);
    printf("Ano: %d\n", melhorFilme->ano);
}

void salvarCatalogo(struct filmes *catalogo[]) {

    FILE *arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < MAX_FILMES; i++) {

        if (catalogo[i] != NULL) {

            fprintf(arquivo, "%d|%s|%s|%d|%.1f\n",
                catalogo[i]->codigo,
                catalogo[i]->nome,
                catalogo[i]->genero,
                catalogo[i]->ano,
                catalogo[i]->nota);
        }
    }

    fclose(arquivo);

    printf("\nCatalogo salvo com sucesso!\n");
}

void liberarCatalogo(struct filmes *catalogo[]) {

    for (int i = 0; i < MAX_FILMES; i++) {

        if (catalogo[i] != NULL) {
            free(catalogo[i]);
            catalogo[i] = NULL;
        }
    }

    printf("\nMemoria liberada com sucesso!\n");
}