#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se uma posição está ocupada
int estaOcupado(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] != 0;
}

int main() {
    // Declaração e inicialização do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // === Definindo as posições dos navios ===
    // Navio 1 - Horizontal (linha 2, coluna 3)
    int linha_h1 = 2;
    int coluna_h1 = 3;

    // Navio 2 - Vertical (linha 5, coluna 7)
    int linha_v1 = 5;
    int coluna_v1 = 7;

    // Navio 3 - Diagonal principal (linha 0, coluna 0)
    int linha_d1 = 0;
    int coluna_d1 = 0;

    // Navio 4 - Diagonal secundária (linha 0, coluna 9)
    int linha_d2 = 0;
    int coluna_d2 = 9;

    // === Validação e posicionamento dos navios ===

    // Navio Horizontal
    if (coluna_h1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (estaOcupado(tabuleiro, linha_h1, coluna_h1 + i)) {
            printf("Erro: Sobreposição no navio horizontal!\n");
            return 1;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_h1][coluna_h1 + i] = NAVIO;
    }

    // Navio Vertical
    if (linha_v1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites!\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (estaOcupado(tabuleiro, linha_v1 + i, coluna_v1)) {
            printf("Erro: Sobreposição no navio vertical!\n");
            return 1;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v1 + i][coluna_v1] = NAVIO;
    }

    // Navio Diagonal Principal (\)
    if (linha_d1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna_d1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio diagonal principal fora dos limites!\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (estaOcupado(tabuleiro, linha_d1 + i, coluna_d1 + i)) {
            printf("Erro: Sobreposição no navio diagonal principal!\n");
            return 1;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_d1 + i][coluna_d1 + i] = NAVIO;
    }

    // Navio Diagonal Secundária (/)
    if (linha_d2 + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna_d2 - (TAMANHO_NAVIO - 1) < 0) {
        printf("Erro: Navio diagonal secundaria fora dos limites!\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (estaOcupado(tabuleiro, linha_d2 + i, coluna_d2 - i)) {
            printf("Erro: Sobreposição no navio diagonal secundaria!\n");
            return 1;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_d2 + i][coluna_d2 - i] = NAVIO;
    }

    // === Exibir o tabuleiro ===
    printf("\nTabuleiro final com os navios posicionados:\n");
    exibirTabuleiro(tabuleiro);


    return 0;
}
