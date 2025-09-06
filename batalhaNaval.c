#include <stdio.h>

int main() {
    // Dimensão fixa do tabuleiro
    const int tamanho = 10;
    int tabuleiro[10][10];

    // Inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho dos navios
    const int tamNavio = 3;

    // Coordenadas iniciais dos navios (fixas neste nível)
    int linhaNavioH = 2, colunaNavioH = 1; // Navio horizontal começa em (2,1)
    int linhaNavioV = 5, colunaNavioV = 4; // Navio vertical começa em (5,4)

    // Posiciona navio horizontal (linha fixa, varia a coluna)
    for (int i = 0; i < tamNavio; i++) {
        tabuleiro[linhaNavioH][colunaNavioH + i] = 3;
    }

    // Posiciona navio vertical (coluna fixa, varia a linha)
    for (int i = 0; i < tamNavio; i++) {
        tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
    }

    // Exibe o tabuleiro
    printf("=== Tabuleiro Batalha Naval ===\n\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
