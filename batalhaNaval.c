#include <stdio.h>

int main() {
    // Tabuleiro 10x10 inicializado com 0 (representa água)
    int tabuleiro[10][10] = {0};
    int i, j;

    // Tamanho fixo dos navios
    int tamanhoNavio = 3;

    // ---------------------------
    // Posicionando os navios retos
    // ---------------------------

    // Navio 1 - horizontal (linha 0, colunas 0 a 2)
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[0][i] = 3;
    }

    // Navio 2 - vertical (coluna 5, linhas 2 a 4)
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[2 + i][5] = 3;
    }

    // ---------------------------
    // Posicionando os navios diagonais
    // ---------------------------

    // Navio 3 - diagonal principal (começa em [6][6])
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[6 + i][6 + i] = 3;
    }

    // Navio 4 - diagonal secundária (começa em [4][6])
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[4 + i][6 - i] = 3;
    }

    // ---------------------------
    // Exibindo o tabuleiro
    // ---------------------------
    printf("Tabuleiro Batalha Naval (10x10):\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // imprime linha
        }
        printf("\n"); // quebra de linha
    }

    return 0;
}

