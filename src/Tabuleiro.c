#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Tabuleiro.h"
#include "JogadorTeclado.h"

void desenha(char tabuleiro[][3]) {
		printf("\033[2J\033[H");
		printf("\n");
        printf("\t_%c_|_%c_|_%c_\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
		printf("\t_%c_|_%c_|_%c_\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
		printf("\t %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
        printf("\n");
}

VerificaoVencedor temVencedor(int matrizPosicoes[][3], int posicoesJogadas) {
    int i, j, somaLinhas, somaColunas;
    for (i = 0; i < 3; i++) {
        somaLinhas = 0;
        somaColunas = 0;
        for (j = 0; j < 3; j++) {
            somaLinhas += matrizPosicoes[i][j];
            somaColunas += matrizPosicoes[j][i];
            if (somaLinhas == 300 || somaColunas == 300) {
                return VENCEDOR_1_JOGADOR;
            } else if (somaLinhas == 1200 || somaColunas == 1200) {
                return VENCEDOR_2_JOGADOR;
            }
        }
	}

    int somaDiagonalP = 0, somaDiagonalS = 0;
    for (i = 0; i < 3; i++) {
        somaDiagonalP += matrizPosicoes[i][i];
        somaDiagonalS += matrizPosicoes[i][2-i];
	}
    if (somaDiagonalP == 300 || somaDiagonalS == 300) {
        return VENCEDOR_1_JOGADOR;
    } else if (somaDiagonalP == 1200 || somaDiagonalS == 1200) {
        return VENCEDOR_2_JOGADOR;
    }

    if (posicoesJogadas == 9) {
        return EMPATE;
    } else {
        return SEM_VENCEDOR;
    }
}

void marcaJogada(int matrizPosicoes[][3], char tabuleiro[][3], char nomeJogador1[], char nomeJogador2[], char simboloJ1, char simboloJ2, int *turno_jogador, int *posicaoEscolhida) {
    setlocale(LC_ALL, "Portuguese");
    int i, j, posicaoInvalida = 1;

    if (*turno_jogador == 1) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (matrizPosicoes[i][j] == *posicaoEscolhida) {
                    matrizPosicoes[i][j] = 100;
                    tabuleiro[i][j] = simboloJ1;
                    posicaoInvalida = 0;
                }
            }
        }
        if (posicaoInvalida == 0) {
            *turno_jogador = 2;
        }

    } else if (*turno_jogador == 2) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (matrizPosicoes[i][j] == *posicaoEscolhida) {
                    matrizPosicoes[i][j] = 400;
                    tabuleiro[i][j] = simboloJ2;
                    posicaoInvalida = 0;
                }
            }
        }
        if (posicaoInvalida == 0) {
            *turno_jogador = 1;
        }
    }

    RespostaVerificaoPosicao resultado = verificao_posicao_escolhida(posicaoEscolhida, &posicaoInvalida);
    if (resultado == POSICAO_JA_OCUPADA) {
        printf("Essa posição já está ocupada! Tente novamente\n");
        system("pause");
        desenha(tabuleiro);
        joga(posicaoEscolhida, nomeJogador1, nomeJogador2, turno_jogador);
        marcaJogada(matrizPosicoes, tabuleiro, nomeJogador1, nomeJogador2, simboloJ1, simboloJ2, turno_jogador, posicaoEscolhida);

    } else if (resultado == POSICAO_INVALIDA){
        printf("Essa posição não existe! As posições possíveis são apenas de 1 a 9\n");
        system("pause");
        desenha(tabuleiro);
        joga(posicaoEscolhida, nomeJogador1, nomeJogador2, turno_jogador);
        marcaJogada(matrizPosicoes, tabuleiro, nomeJogador1, nomeJogador2, simboloJ1, simboloJ2, turno_jogador, posicaoEscolhida);
    }
}

RespostaVerificaoPosicao verificao_posicao_escolhida(int *posicaoEscolhida, int *posicaoInvalida) {
    if ((*posicaoEscolhida > 0 && *posicaoEscolhida < 10) && *posicaoInvalida == 1) {
        return POSICAO_JA_OCUPADA;
    } else if (*posicaoEscolhida < 1 || *posicaoEscolhida > 9) {
        return POSICAO_INVALIDA;
    } else {
        return POSICAO_VALIDA;
    }
}