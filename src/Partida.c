#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Tabuleiro.h"
#include "JogadorTeclado.h"
#include "Partida.h"

void configuraJogadores(char nomeJogador1[], char nomeJogador2[], char *simboloJ1, char *simboloJ2, char *simboloIA, int *turno_jogador, int *modoDeJogo){
    setlocale(LC_ALL, "Portuguese");
    
    printf("Digite o modo de jogo: <1> PvP; <2> PvIA\nDigite aqui: ");
    scanf("%d", modoDeJogo);

    switch (*modoDeJogo) {
        case 1:
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
            break;
        case 2:
            nomeJogador1 = "IA";
            printf("Digite o nome do jogador: ");
            scanf("%s", nomeJogador2);

            printf("\n%s, você quer ser X ou O? (Digite em caixa alta)\nDigite aqui: ", nomeJogador2);
            scanf(" %c", simboloJ2);

            if(*simboloJ2 == 'X'){
                *simboloIA = 'O';
            } else {
                *simboloIA = 'X';
            }

            *turno_jogador = 1;
            printf("\nConfiguracao aceita!\n");
            printf("%s vai jogar com: %c\n", nomeJogador2, *simboloJ2);
            printf("A IA vai jogar com: %c\n", *simboloIA);
            system("pause");
            printf("\033[2J\033[H");
            break;
    }
    
}

void inicia(int *turno_jogador, char nomeJogador1[], char nomeJogador2[], char simboloJ1, char simboloJ2, char simboloIA, int modoDeJogo){
    setlocale(LC_ALL, "Portuguese");
    int totalPosicoesJogadas = 0, posicaoEscolhida;
    int matrizPosicoes[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	char tabuleiro[3][3] = {{'_','_','_'}, {'_','_','_'}, {' ',' ',' '}};
    VerificaoVencedor resultado;
	
    while(1) {
        desenha(tabuleiro);
        joga(matrizPosicoes, &posicaoEscolhida, nomeJogador1, nomeJogador2, turno_jogador, modoDeJogo);
        marcaJogada(matrizPosicoes, tabuleiro, nomeJogador1, nomeJogador2, simboloJ1, simboloJ2, simboloIA, turno_jogador, &posicaoEscolhida, modoDeJogo);
        totalPosicoesJogadas += 1;

        resultado = temVencedor(matrizPosicoes, totalPosicoesJogadas);
        if (resultado == VENCEDOR_1_JOGADOR) {
            desenha(tabuleiro);

            if (modoDeJogo == 1) {
                printf("%s venceu!!\n", nomeJogador1);
            } else {
                printf("A IA venceu!!\n");
            }
            system("pause");
            break;
        } else if (resultado == VENCEDOR_2_JOGADOR) {
            desenha(tabuleiro);
            printf("%s venceu!!\n", nomeJogador2);
            system("pause");
            break;
        } else if (resultado == EMPATE){
            desenha(tabuleiro);

            if (modoDeJogo == 1) {
                printf("%s e %s empataram!!\n", nomeJogador1, nomeJogador2);
            } else {
                printf("%s e a IA empataram!!\n", nomeJogador2);
            }

            system("pause");
            break;
        } else {
            continue;
        }
    }
	
}