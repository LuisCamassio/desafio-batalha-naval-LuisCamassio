#include <stdio.h>

#define N 10   // tamanho do tabuleiro
#define M 5    // tamanho das matrizes de habilidade (5x5)

// Função para imprimir o tabuleiro
void imprimeTabuleiro(int tabuleiro[N][N]) {
    int i, j;
    printf("\nTabuleiro Batalha Naval:\n\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar uma matriz de habilidade no tabuleiro
void aplicaHabilidade(int tabuleiro[N][N], int habilidade[M][M], int origemLinha, int origemColuna) {
    int i, j;

    // Percorre a matriz da habilidade
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            if (habilidade[i][j] == 1) { // posição afetada
                // Calcula posição correspondente no tabuleiro
                int linha = origemLinha + (i - M/2);
                int coluna = origemColuna + (j - M/2);

                // Verifica se está dentro do tabuleiro
                if (linha >= 0 && linha < N && coluna >= 0 && coluna < N) {
                    if (tabuleiro[linha][coluna] == 0) { 
                        tabuleiro[linha][coluna] = 5; // marca área afetada (sem sobrescrever navio)
                    }
                }
            }
        }
    }
}

int main() {
    int i, j;
    int tabuleiro[N][N] = {0}; // inicia com água (0)

    // --------------------------
    // Navios fixos
    // --------------------------
    // Navio horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[0][i] = 3;
    }
    // Navio vertical
    for (i = 0; i < 3; i++) {
        tabuleiro[2+i][5] = 3;
    }
    // Navio diagonal principal
    for (i = 0; i < 3; i++) {
        tabuleiro[6+i][6+i] = 3;
    }
    // Navio diagonal secundária
    for (i = 0; i < 3; i++) {
        tabuleiro[4+i][6-i] = 3;
    }

    // --------------------------
    // Matrizes de habilidades
    // --------------------------
    int cone[M][M] = {0};
    int cruz[M][M] = {0};
    int octaedro[M][M] = {0};

    // Cone (expande para baixo)
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            if (j >= M/2 - i && j <= M/2 + i && i <= M/2) {
                cone[i][j] = 1;
            }
        }
    }

    // Cruz (linha e coluna central)
    for (i = 0; i < M; i++) {
        cruz[M/2][i] = 1; // linha central
        cruz[i][M/2] = 1; // coluna central
    }

    // Octaedro (losango)
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            if (abs(i - M/2) + abs(j - M/2) <= M/2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // --------------------------
    // Aplicando habilidades no tabuleiro
    // --------------------------
    aplicaHabilidade(tabuleiro, cone, 2, 2);      // origem em (2,2)
    aplicaHabilidade(tabuleiro, cruz, 5, 5);      // origem em (5,5)
    aplicaHabilidade(tabuleiro, octaedro, 7, 3);  // origem em (7,3)

    // --------------------------
    // Exibir resultado final
    // --------------------------
    imprimeTabuleiro(tabuleiro);

    return 0;
}


