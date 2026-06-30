#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Tabuleiro.h"
#include "JogadorTeclado.h"
#include "Partida.h"

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