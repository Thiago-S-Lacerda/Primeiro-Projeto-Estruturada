#include <stdio.h>
#include <locale.h>
#include "Partida.h"
#include "JogadorTeclado.h"
#include "JogadorIA.h"

void joga(int matrizPosicoes[][3], int *posicaoEscolhida, char nomeJogador1[], char nomeJogador2[], int *turno_jogador, int modoDeJogo) {
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