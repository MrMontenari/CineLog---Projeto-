#include <stdio.h>
#include "filmes.h"

int main () {
    
    struct filmes *catalogo[MAX_FILMES];
    int choose =0;

    inicializarCatalogo(catalogo);
    carregarCatalogo(catalogo);

    //-------------------------------------/
    do {
        printf("\n===== CineLog =====\n");
        printf("1. Cadastrar filme\n");
        printf("2. Listar catalogo\n");
        printf("3. Buscar filme\n");
        printf("4. Relatorios\n");
        printf("5. Salvar e sair\n");
        printf("===================\n");
        printf("Escolha uma opcao: ");

    scanf("%d", &choose); 

    switch (choose) {

        case 1:
            cadastrarFilme(catalogo);
            break;

        case 2:
            listarFilmes(catalogo);
            break;

        case 3:
            buscarFilme(catalogo);
            break;

        case 4:
            gerarRelatorios(catalogo);
            break;

        case 5:
            salvarCatalogo(catalogo);
            liberarCatalogo(catalogo);

            printf("Saindo do CineLog...\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

} while (choose !=5);
    return 0;
}

void carregarCatalogo(struct filmes *catalogo[]) {

    FILE *arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("\nNenhum arquivo encontrado. Iniciando catalogo vazio.\n");
        return;
    }

    char linha[300];

    for (int i = 0; i < MAX_FILMES && fgets(linha, sizeof(linha), arquivo) != NULL; i++) {

        catalogo[i] = malloc(sizeof(struct filmes));

        if (catalogo[i] == NULL) {
            printf("\nErro ao alocar memoria!\n");
            break;
        }

        int resultado = sscanf(linha, "%d|%99[^|]|%49[^|]|%d|%f",
            &catalogo[i]->codigo,
            catalogo[i]->nome,
            catalogo[i]->genero,
            &catalogo[i]->ano,
            &catalogo[i]->nota);

        if (resultado != 5) {
            free(catalogo[i]);
            catalogo[i] = NULL;
            printf("\nRegistro invalido encontrado no arquivo.\n");
            break;
        }
    }

    fclose(arquivo);

    printf("\nCatalogo carregado com sucesso!\n");
}
