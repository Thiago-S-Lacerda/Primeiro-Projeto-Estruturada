#ifndef _Partida_H
#define _Partida_H

typedef enum {
    MODO_PVP,
    MODO_IA,
    MODO_SERVIDOR,
    MODO_CLIENTE
} ModoDeJogo;

void configuraJogadores(char nomeJogador1[], char nomeJogador2[], char *simboloJ1, char *simboloJ2, char *simboloIA, int *turno_jogador, ModoDeJogo modoDeJogo);

void inicia(int *turno_jogador, char nomeJogador1[], char nomeJogador2[], char simboloJ1, char simboloJ2, char simboloIA, ModoDeJogo modoDeJogo);

#endif