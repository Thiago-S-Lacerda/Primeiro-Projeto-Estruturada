#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <winsock2.h>
#include "Tabuleiro.h"
#include "JogadorTeclado.h"
#include "Partida.h"
#include "JogadorIA.h"
#include "JogadorRemoto.h"

void configuraJogadores(char nomeJogador1[], char nomeJogador2[], char *simboloJ1, char *simboloJ2, char *simboloIA, int *turno_jogador, ModoDeJogo modoDeJogo){
    setlocale(LC_ALL, "Portuguese");

    switch (modoDeJogo) {
        case MODO_PVP:
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
        case MODO_IA:
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

void inicia(int *turno_jogador, char nomeJogador1[], char nomeJogador2[], char simboloJ1, char simboloJ2, char simboloIA, ModoDeJogo modoDeJogo){
    setlocale(LC_ALL, "Portuguese");
    int totalPosicoesJogadas = 0, posicaoEscolhida;
    int matrizPosicoes[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	char tabuleiro[3][3] = {{'_','_','_'}, {'_','_','_'}, {' ',' ',' '}};
    VerificaoVencedor resultado;
    SOCKET sock, sock_resposta;
	
    if (modoDeJogo == MODO_SERVIDOR) {
        sock = ligarServidor();
        aceitaCliente(sock, &sock_resposta);
    } else if (modoDeJogo == MODO_CLIENTE) {
        sock = conecta();
    }

    while(1) {
        desenha(tabuleiro);
        if (modoDeJogo == MODO_SERVIDOR) {
            jogaRemoto(&posicaoEscolhida, turno_jogador, HOST, sock_resposta);
        } else if (modoDeJogo == MODO_CLIENTE) {
            jogaRemoto(&posicaoEscolhida, turno_jogador, CLIENTE, sock);
        } else if (modoDeJogo == MODO_IA) {
            jogaIA(matrizPosicoes, &posicaoEscolhida, nomeJogador2, turno_jogador);
        } else {
            joga(&posicaoEscolhida, nomeJogador1, nomeJogador2, turno_jogador);
        }
        marcaJogada(matrizPosicoes, tabuleiro, simboloJ1, simboloJ2, simboloIA, turno_jogador, &posicaoEscolhida, &totalPosicoesJogadas, modoDeJogo, sock);

        resultado = temVencedor(matrizPosicoes, totalPosicoesJogadas);
        if (resultado == VENCEDOR_1_JOGADOR) {
            desenha(tabuleiro);

            if (modoDeJogo == MODO_PVP) {
                printf("%s venceu!!\n", nomeJogador1);
            } else if (modoDeJogo == MODO_IA){
                printf("A IA venceu!!\n");
            } else {
                printf("O Host venceu!!\n");
            }
            system("pause");
            break;
        } else if (resultado == VENCEDOR_2_JOGADOR) {
            desenha(tabuleiro);

            if (modoDeJogo == MODO_SERVIDOR || modoDeJogo == MODO_CLIENTE) {
                printf("O Cliente venceu!!\n");
            } else {
                printf("%s venceu!!\n", nomeJogador2);
            }
            system("pause");
            break;
        } else if (resultado == EMPATE){
            desenha(tabuleiro);

            if (modoDeJogo == MODO_PVP) {
                printf("%s e %s empataram!!\n", nomeJogador1, nomeJogador2);
            } else if (modoDeJogo == MODO_IA) {
                printf("%s e a IA empataram!!\n", nomeJogador2);
            } else {
                printf("O Host e o Cliente empataram\n");
            }
            system("pause");
            break;
        } else {
            continue;
        }
    }
	
    if (modoDeJogo == MODO_SERVIDOR) {
        closesocket(sock_resposta);
        closesocket(sock);
    } else if (modoDeJogo == MODO_CLIENTE) {
        closesocket(sock);
    }
    WSACleanup();
}