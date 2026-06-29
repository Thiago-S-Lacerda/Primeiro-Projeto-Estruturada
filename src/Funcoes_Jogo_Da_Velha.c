#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Funcoes_Jogo_Da_Velha.h"

void configuraJogadores(char nomeJogador1[], char nomeJogador2[], char *simboloJ1, char *simboloJ2, int *turno_jogador){
    setlocale(LC_ALL, "Portuguese");
    
    printf("Digite o nome do 1º jogador: ");
    scanf("%s", nomeJogador1);
    printf("Digite o nome do 2º jogador: ");
    scanf("%s", nomeJogador2);

    printf("\n%s, você quer ser X ou O? (Digite em caixa alta)\nDigite aqui: ", nomeJogador1);
    scanf(" %c", simboloJ1);

    if(*simboloJ1 == 'X'){
        *simboloJ2 = 'O';
    } else {
        *simboloJ2 = 'X';
    }

    printf("Quem vai começar? %s <1> ou %s <2>?\nDigite aqui: ", nomeJogador1, nomeJogador2);
    scanf("%d", turno_jogador);

    printf("\nConfiguracao aceita!\n");
    printf("%s vai jogar com: %c\n", nomeJogador1, *simboloJ1);
    printf("%s vai jogar com: %c\n", nomeJogador2, *simboloJ2);
    system("pause");
    printf("\033[2J\033[H");
}

void inicia(int matrizPosicoes[][3], char tabuleiro[][3], int *turno_jogador, char nomeJogador1[], char nomeJogador2[], char simboloJ1, char simboloJ2){
    setlocale(LC_ALL, "Portuguese");
    int totalPosicoesJogadas = 0, posicaoEscolhida;
    VerificaoVencedor resultado;

    printf("Exemplo das posições:\n");
	printf("\t_1_|_2_|_3_\n");
	printf("\t_4_|_5_|_6_\n");
	printf("\t 7 | 8 | 9 \n");
	system("pause");
	
	while(1) {
        desenha(tabuleiro);
        joga(&posicaoEscolhida, nomeJogador1, nomeJogador2, turno_jogador);
        marcaJogada(matrizPosicoes, tabuleiro, nomeJogador1, nomeJogador2, simboloJ1, simboloJ2, turno_jogador, &posicaoEscolhida);
        totalPosicoesJogadas += 1;

        resultado = temVencedor(matrizPosicoes, totalPosicoesJogadas);
        if (resultado == VENCEDOR_1_JOGADOR) {
			desenha(tabuleiro);
			printf("%s venceu!!", nomeJogador1);
			break;
		} else if (resultado == VENCEDOR_2_JOGADOR) {
			desenha(tabuleiro);
			printf("%s venceu!!", nomeJogador2);
			break;
        } else if (resultado == EMPATE){
            desenha(tabuleiro);
            printf("%s e %s empataram!!", nomeJogador1, nomeJogador2);
            break;
        } else {
            continue;
        }
    }
}

void desenha(char tabuleiro[][3]) {
		printf("\033[2J\033[H");
		printf("\n");
        printf("\t_%c_|_%c_|_%c_\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
		printf("\t_%c_|_%c_|_%c_\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
		printf("\t %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
        printf("\n");
}

void joga(int *posicaoEscolhida, char nomeJogador1[], char nomeJogador2[], int *turno_jogador) {
    setlocale(LC_ALL, "Portuguese");

    if (*turno_jogador == 1) {
        printf("Vez de %s\n", nomeJogador1);
        printf("Digite a posição que você quer jogar: ");
        scanf("%d", posicaoEscolhida);
    } else if (*turno_jogador == 2) {
        printf("Vez de %s\n", nomeJogador2);
        printf("Digite a posição que você quer jogar: ");
        scanf("%d", posicaoEscolhida);
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

VerificaoVencedor temVencedor(int matrizPosicoes[][3], int posicoesJogadas) {
    // Verificação das linhas e colunas
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
    // Verificação das diagonais
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