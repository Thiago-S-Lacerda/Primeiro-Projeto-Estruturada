#include <stdio.h>
#include <windows.h>
#include "Regras.h"
#include "JogadorIA.h"

int jogaIA(int matrizPosicoes[][3], int *posicaoEscolhida, char nomeJogador2[], int *turno_jogador) {
    if (*turno_jogador == 1) {
        printf("Vez da IA\n");
        *posicaoEscolhida = pensaIA(matrizPosicoes);
    } else if (*turno_jogador == 2) {
        printf("Vez de %s\n", nomeJogador2);
        printf("Digite a posição que você quer jogar: ");
        scanf("%d", posicaoEscolhida);
    }
}

int pensaIA(int matrizPosicoes[][3]) {
    printf("\nIA pensando na jogada...\n");
    Sleep(1500);

    int regra1 = regra1IA(matrizPosicoes);
    if(regra1 != 0) {
        return regra1;
    }

    int regra2 = regra2IA(matrizPosicoes);
    if(regra2 != 0) {
        return regra2;
    }

    int regra3 = regra3IA(matrizPosicoes);
    if (regra3 != 0) {
        return regra3;
    }

    int regra4 = regra4IA(matrizPosicoes);
    if (regra4 != 0) {
        return regra4;
    }

    int regra5 = regra5IA(matrizPosicoes);
    if (regra5 != 0) {
        return regra5;
    }

    int regra6 = regra6IA(matrizPosicoes);
    if (regra6 != 0) {
        return regra6;
    }
}