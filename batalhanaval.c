
#include <stdio.h>

// Constantes do jogo
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== Tabuleiro ===\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o navio pode ser posicionado sem ultrapassar o limite ou sobreposição
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    if (direcao == 'H') {
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != AGUA) return 0;
        }
    } else if (direcao == 'V') {
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != AGUA) return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 'H') {
            tabuleiro[linha][coluna + i] = NAVIO;
        } else if (direcao == 'V') {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicialização do tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas pré-definidas
    int linhaNavioH = 2, colunaNavioH = 3; // Navio horizontal
    int linhaNavioV = 5, colunaNavioV = 7; // Navio vertical

    // Validação e posicionamento dos navios
    if (podePosicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, 'H')) {
        posicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, 'H');
    } else {
        printf("Erro: Navio horizontal não pode ser posicionado.\n");
    }

    if (podePosicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, 'V')) {
        posicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, 'V');
    } else {
        printf("Erro: Navio vertical não pode ser posicionado.\n");
    }

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}