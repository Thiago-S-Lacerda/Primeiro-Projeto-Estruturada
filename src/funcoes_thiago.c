#include <stdio.h>
#include <locale.h>
#include "funcoes_thiago.h"

void desenha(int matrizJogada[][3], char tabuleiro[][3]) {
		printf("\033[2J\033[H");
		printf("\n");
        printf("\t_%c_|_%c_|_%c_\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
		printf("\t_%c_|_%c_|_%c_\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
		printf("\t %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
        printf("\n");
}

void marcaJogada(int matrizJogada[][3], char tabuleiro[][3], char jogador1[], char jogador2[]) {
    setlocale(LC_ALL, "Portuguese");
    int posicao, i, j;
	
    static int turno_jogador = 2;

    if (turno_jogador == 1) {
        printf("Vez de %s\n", jogador1);
        printf("Digite a posição que você quer jogar: ");
        scanf("%d", &posicao);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (matrizJogada[i][j] == posicao) {
                    matrizJogada[i][j] = 100;
                    tabuleiro[i][j] = 'O';
                }
            }
        }
        turno_jogador = 2;
    } else if (turno_jogador == 2) {
        printf("Vez de %s\n", jogador2);
        printf("Digite a posição que você quer jogar: ");
        scanf("%d", &posicao);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (matrizJogada[i][j] == posicao) {
                    matrizJogada[i][j] = 400;
                    tabuleiro[i][j] = 'X';
                }
            }
        }
        turno_jogador = 1;
    }
}