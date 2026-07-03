#ifndef _Partida_H
#define _Partida_H

void configuraJogadores(char nomeJogador1[], char nomeJogador2[], char *simboloJ1, char *simboloJ2, char *simboloIA, int *turno_jogador, int *modoDeJogo);

void inicia(int *turno_jogador, char nomeJogador1[], char nomeJogador2[], char simboloJ1, char simboloJ2, char simboloIA, int modoDeJogo);

#endif