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
#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

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

int main() {
    // Declaração e inicialização do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Definição das coordenadas iniciais dos navios
    // Navio horizontal começa na linha 2, coluna 3
    int linha_horizontal = 2;
    int coluna_horizontal = 3;

    // Navio vertical começa na linha 5, coluna 7
    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Validação dos limites para navio horizontal
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }

    // Validação dos limites para navio vertical
    if (linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites!\n");
        return 1;
    }

    // Verificar se há sobreposição para navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
            printf("Erro: Sobreposição detectada no navio horizontal!\n");
            return 1;
        }
    }

    // Posicionar o navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Verificar se há sobreposição para navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
            printf("Erro: Sobreposição detectada no navio vertical!\n");
            return 1;
        }
    }

    // Posicionar o navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // Exibir o tabuleiro final
    printf("\nTabuleiro final com os navios posicionados:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
