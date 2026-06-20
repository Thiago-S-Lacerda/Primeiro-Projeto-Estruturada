#include <stdio.h>
#include <stdlib.h>
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
    int posicao, i, j, posicaoInvalida = 1;
	
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
                    posicaoInvalida = 0;
                }
            }
        }
        if (posicaoInvalida == 0) {
            turno_jogador = 2;
        }

    } else if (turno_jogador == 2) {
        printf("Vez de %s\n", jogador2);
        printf("Digite a posição que você quer jogar: ");
        scanf("%d", &posicao);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (matrizJogada[i][j] == posicao) {
                    matrizJogada[i][j] = 400;
                    tabuleiro[i][j] = 'X';
                    posicaoInvalida = 0;
                }
            }
        }
        if (posicaoInvalida == 0) {
            turno_jogador = 1;
        }
    }

    if ((posicao > 0 && posicao < 10) && posicaoInvalida == 1) {
        printf("Essa posição já está ocupada! Tente novamente\n");
        system("pause");
        desenha(matrizJogada, tabuleiro);
        marcaJogada(matrizJogada, tabuleiro, jogador1, jogador2);
    } else if (posicao < 1 || posicao > 9) {
        printf("Essa posição não existe! As posições possíveis são apenas de 0 a 9\n");
        system("pause");
        desenha(matrizJogada, tabuleiro);
        marcaJogada(matrizJogada, tabuleiro, jogador1, jogador2);
    }
}

int temVencedor(int matrizJogada[][3], char jogador1[], char jogador2[]) {
    // Verificação das linhas e colunas
    int i, j, somaLinhas, somaColunas;
    for (i = 0; i < 3; i++) {
        somaLinhas = 0;
        somaColunas = 0;
        for (j = 0; j < 3; j++) {
            somaLinhas += matrizJogada[i][j];
            somaColunas += matrizJogada[j][i];
            if (somaLinhas == 300 || somaColunas == 300) {
                printf("%s venceu!!", jogador1);
                return 1;
            } else if (somaLinhas == 1200 || somaColunas == 1200) {
                printf("%s venceu!!", jogador2);
                return 2;
            }
        }
	}

    // Verificação das diagonais
    int somaDiagonalP = 0, somaDiagonalS = 0;
    for (i = 0; i < 3; i++) {
        somaDiagonalP += matrizJogada[i][i];
        somaDiagonalS += matrizJogada[i][2-i];
	}
    if (somaDiagonalP == 300 || somaDiagonalS == 300) {
                printf("%s venceu!!", jogador1);
                return 1;
            } else if (somaDiagonalP == 1200 || somaDiagonalS == 1200) {
                printf("%s venceu!!", jogador2);
                return 2;
            }

    return 0;
}