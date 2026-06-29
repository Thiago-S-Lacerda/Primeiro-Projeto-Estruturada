#ifndef _Funcoes_Jogo_Da_Velha_H
#define _Funcoes_Jogo_Da_Velha_H

typedef enum {
    VENCEDOR_1_JOGADOR,
    VENCEDOR_2_JOGADOR,
    EMPATE,
    SEM_VENCEDOR
} VerificaoVencedor;

typedef enum {
    POSICAO_INVALIDA,
    POSICAO_JA_OCUPADA,
    POSICAO_VALIDA
} RespostaVerificaoPosicao;

void configuraJogadores(char nomeJogador1[], char nomeJogador2[], char *simboloJ1, char *simboloJ2, int *turno_jogador);

void inicia(int matrizPosicoes[][3], char tabuleiro[][3], int *turno_jogador, char nomeJogador1[], char nomeJogador2[], char simboloJ1, char simboloJ2);

void desenha(char tabuleiro[][3]);

void joga(int *posicaoEscolhida, char nomeJogador1[], char nomeJogador2[], int *turno_jogador);

RespostaVerificaoPosicao verificao_posicao_escolhida(int *posicaoEscolhida, int *posicaoInvalida);

void marcaJogada(int matrizPosicoes[][3], char tabuleiro[][3], char nomeJogador1[], char nomeJogador2[], char simboloJ1, char simboloJ2, int *turno_jogador, int *posicaoEscolhida);

VerificaoVencedor temVencedor(int matrizPosicoes[][3], int posicoesJogadas);

#endif