# CineLog — Catálogo de Filmes e Séries

## Identificação

- **Aluno:** Matheus Gonçalves Cardoso

## Motivo da escolha do tema

Escolhi desenvolver um catálogo de filmes e séries porque gosto bastante de assistir a esse tipo de conteúdo e tenho mais interesse por filmes e séries do que por jogos digitais.

A escolha também tornou o desenvolvimento mais interessante, pois trabalhei com um tema com o qual já tenho familiaridade.

## Modelagem e desenvolvimento do projeto

O desenvolvimento foi realizado de maneira gradual, dividindo o problema em partes menores.

Em cada etapa, revisei os conceitos teóricos apresentados nas aulas e, em seguida, apliquei esses conhecimentos na implementação do sistema.

O projeto foi organizado em três arquivos principais:

- **filmes.h:** contém a estrutura `struct filmes`, a constante `MAX_FILMES` e os protótipos das funções.
- **filmes.c:** contém a implementação das funções responsáveis pelo gerenciamento do catálogo.
- **main.c:** contém a função principal, o menu e o controle das operações do programa.

A estrutura de cada filme possui os seguintes campos:

- Código;
- Nome;
- Gênero;
- Ano de lançamento;
- Nota de avaliação.

Para armazenar os registros, foi utilizado um vetor de ponteiros com capacidade para 100 filmes. A memória é alocada dinamicamente com `malloc()` durante os cadastros e liberada com `free()` ao encerrar o programa.

O sistema também utiliza arquivos de texto para persistência dos dados, permitindo salvar o catálogo em `dados.txt` e carregá-lo automaticamente na próxima execução.

## Funcionalidades implementadas

1. Cadastro de filmes e séries;
2. Listagem de todos os títulos cadastrados;
3. Busca de títulos pelo código;
4. Relatório com a maior nota e a média geral das avaliações;
5. Salvamento e carregamento dos dados em arquivo de texto;
6. Liberação da memória alocada dinamicamente.

## Compilação e execução

É necessário ter o compilador GCC instalado.

Abra o terminal na pasta do projeto e execute:

```bash
gcc main.c filmes.c -Wall -Wextra -o CineLog
```

Para executar o programa:

```bash
./CineLog
```

O arquivo `dados.txt` é utilizado para armazenar os registros do catálogo.
