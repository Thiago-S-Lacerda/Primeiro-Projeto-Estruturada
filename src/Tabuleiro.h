#ifndef _Tabuleiro_H
#define _Tabuleiro_H

typedef enum {
    VENCEDOR_1_JOGADOR,
    VENCEDOR_2_JOGADOR,
    EMPATE,
    SEM_VENCEDOR
} VerificaoVencedor;

typedef enum {
    POSICAO_INVALIDA,
    POSICAO_VALIDA
} RespostaVerificaoPosicao;

void desenha(char tabuleiro[][3]);

VerificaoVencedor temVencedor(int matrizPosicoes[][3], int posicoesJogadas);

void marcaJogada(int matrizPosicoes[][3], char tabuleiro[][3], char nomeJogador1[], char nomeJogador2[], char simboloJ1, char simboloJ2, char simboloIA, int *turno_jogador, int *posicaoEscolhida, int modoDeJogo);

RespostaVerificaoPosicao verificao_posicao_escolhida(int *posicaoEscolhida);

#endif