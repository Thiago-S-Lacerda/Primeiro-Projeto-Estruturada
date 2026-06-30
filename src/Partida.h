#ifndef _Partida_H
#define _Partida_H

void configuraJogadores(char nomeJogador1[], char nomeJogador2[], char *simboloJ1, char *simboloJ2, int *turno_jogador);

void inicia(int matrizPosicoes[][3], char tabuleiro[][3], int *turno_jogador, char nomeJogador1[], char nomeJogador2[], char simboloJ1, char simboloJ2);

#endif