#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorTeclado.h"
#include "JogadorRemoto.h"

void desenha(char tabuleiro[][3]) {
		printf("\033[2J\033[H");
        printf("\t\t\t\t    Exemplo das posições:");
		printf("\n");
        printf("\t_%c_|_%c_|_%c_\t\t\t_1_|_2_|_3_\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
		printf("\t_%c_|_%c_|_%c_\t\t\t_4_|_5_|_6_\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
		printf("\t %c | %c | %c \t\t\t 7 | 8 | 9 \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
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

RespostaVerificaoPosicao verificao_posicao_escolhida(int *posicaoEscolhida) {
    if (*posicaoEscolhida < 1 || *posicaoEscolhida > 9) {
        return POSICAO_INVALIDA;
    } else {
        return POSICAO_VALIDA;
    }
}

void marcaJogada(int matrizPosicoes[][3], char tabuleiro[][3], char simboloJ1, char simboloJ2, char simboloIA, int *turno_jogador, int *posicaoEscolhida, int *totalPosicoesJogadas, ModoDeJogo modoDeJogo, SOCKET sock) {
    setlocale(LC_ALL, "Portuguese");
    int posicaoInvalida = 0;
    RespostaVerificaoPosicao resultado = verificao_posicao_escolhida(posicaoEscolhida);
    
    if (resultado == POSICAO_INVALIDA){
        posicaoInvalida = 1;
        if (modoDeJogo == MODO_SERVIDOR && *turno_jogador == 1) {
            printf("Essa posição não existe! As posições possíveis são apenas de 1 a 9\n");
            system("pause");
        } else if (modoDeJogo == MODO_CLIENTE && *turno_jogador == 2) {
            printf("Essa posição não existe! As posições possíveis são apenas de 1 a 9\n");
            system("pause");
        } else if (modoDeJogo == MODO_PVP || modoDeJogo == MODO_IA) {
            printf("Essa posição não existe! As posições possíveis são apenas de 1 a 9\n");
            system("pause");
        }
    }
    if (posicaoInvalida == 0) {
        int linha[9] = {0,0,0,1,1,1,2,2,2};
        int coluna[9] = {0,1,2,0,1,2,0,1,2};

        int p = *posicaoEscolhida - 1;

        int i = linha[p];
        int j = coluna[p];
        if (modoDeJogo == MODO_PVP) {
            if(matrizPosicoes[i][j] != 100 && matrizPosicoes[i][j] != 400){
                if (*turno_jogador == 1) {
                    matrizPosicoes[i][j] = 100;
                    tabuleiro[i][j] = simboloJ1;
                    *turno_jogador = 2;
                } else if (*turno_jogador == 2){
                    matrizPosicoes[i][j] = 400;
                    tabuleiro[i][j] = simboloJ2;
                    *turno_jogador = 1;
                }
                *totalPosicoesJogadas += 1;
            } else {
                printf("Essa posição já está ocupada! Tente novamente\n");
                system("pause");
            }
        } else if (modoDeJogo == MODO_IA) {
            if(matrizPosicoes[i][j] != 100 && matrizPosicoes[i][j] != 400){
                if (*turno_jogador == 1) {
                    matrizPosicoes[i][j] = 100;
                    tabuleiro[i][j] = simboloIA;
                    *turno_jogador = 2;
                } else if (*turno_jogador == 2){
                    matrizPosicoes[i][j] = 400;
                    tabuleiro[i][j] = simboloJ2;
                    *turno_jogador = 1;
                }
                *totalPosicoesJogadas += 1;
            } else {
                printf("Essa posição já está ocupada! Tente novamente\n");
                system("pause");
            }
        } else {
            if(matrizPosicoes[i][j] != 100 && matrizPosicoes[i][j] != 400){
                if (*turno_jogador == 1) {
                    matrizPosicoes[i][j] = 100;
                    tabuleiro[i][j] = 'X';
                    *turno_jogador = 2;
                } else if (*turno_jogador == 2){
                    matrizPosicoes[i][j] = 400;
                    tabuleiro[i][j] = 'O';
                    *turno_jogador = 1;
                }
                *totalPosicoesJogadas += 1;
            } else {
                if (modoDeJogo == MODO_SERVIDOR && *turno_jogador == 1) {
                    printf("Essa posição já está ocupada! Tente novamente\n");
                    system("pause");
                } else if (modoDeJogo == MODO_CLIENTE && *turno_jogador == 2) {
                    printf("Essa posição já está ocupada! Tente novamente\n");
                    system("pause");
                } else if (modoDeJogo == MODO_PVP || modoDeJogo == MODO_IA) {
                    printf("Essa posição não existe! As posições possíveis são apenas de 1 a 9\n");
                    system("pause");
                }
            }
        }
    }
}
