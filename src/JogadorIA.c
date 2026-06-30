#include <stdio.h>
#include <stdlib.h>

int casaLivre(int matrizPosicoes[][3], int numeroProcurado){
    int i, j;
    for (i  = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(matrizPosicoes[i][j] == numeroProcurado){
                return 1;
            }
        }
    }
    return 0;
}
int pensaIA(int matrizPosicoes[][3]) {
    int i, l, c;

    printf("\nIA pensando na jogada...\n");
    system("pause");


    for(l = 0; l < 3; l++){
        int contaJ1 = 0, contaIA = 0, livres = 0, alvo = -1;
        for(c = 0; c < 3; c++){
            if(matrizPosicoes[l][c] == 100) contaJ1++;
            else if(matrizPosicoes[l][c] == 400) contaJ1++;
            else{ livres ++; alvo = matrizPosicoes[l][c]; }
        }
        if(livres == 1 && (contaIA == 2 || contaJ1 == 2)) {
            return alvo;
        }
    }
    for(c = 0; c < 3; c++){
        int contaJ1 = 0, contaIA = 0, livres = 0, alvo = -1;
        for (l = 0; l < 3; l++){
            if (matrizPosicoes[l][c] == 100) contaJ1++;
            else if (matrizPosicoes[l][c] == 400) contaIA++;
            else { livres++; alvo = matrizPosicoes[l][c]; }
        }
        if (livres == 1 && (contaIA == 2 || contaJ1 == 2)){
            return alvo;
        }
    }

    int contaJ1_d1 = 0, contaIA_d1 = 0, livres_d1 = 0, alvo_d1 = -1;
    for(i = 0; i < 3; i++){
        if(matrizPosicoes[i][i] == 100) contaJ1_d1++;
        else if (matrizPosicoes[i][i] == 400) contaIA_d1++;
        else { livres_d1++; alvo_d1 = matrizPosicoes[i][i]; }
    }
    if(livres_d1 && (contaIA_d1 == 2 || contaJ1_d1 == 2)){
        return alvo_d1;
    }
    int contaJ1_d2 = 0, contaIA_d2 = 0, livres_d2 = 0, alvo_d2 = -1;
    for(i = 0; i < 3; i++){
        if(matrizPosicoes[i][2 - i] == 100) contaJ1_d2++;
        else if (matrizPosicoes[i][2 - i] == 400) contaIA_d2++;
        else { livres_d2++; alvo_d2 = matrizPosicoes[i][i]; }
    }
    if(livres_d2 && (contaIA_d2 == 2 || contaJ1_d2 == 2)){
        return alvo_d2;
    }

    if (matrizPosicoes[0][0] == 400 && casaLivre(matrizPosicoes, 9)) return 9;
    if (matrizPosicoes[0][2] == 400 && casaLivre(matrizPosicoes, 7)) return 7;
    if (matrizPosicoes[2][0] == 400 && casaLivre(matrizPosicoes, 3)) return 3;
    if (matrizPosicoes[2][2] == 400 && casaLivre(matrizPosicoes, 1)) return 1;
    if(casaLivre(matrizPosicoes, 5)){
        return 5;
    }
    if (matrizPosicoes[0][0] == 100 && casaLivre(matrizPosicoes, 9)) return 9;
    if (matrizPosicoes[0][2] == 100 && casaLivre(matrizPosicoes, 7)) return 7;
    if (matrizPosicoes[2][0] == 100 && casaLivre(matrizPosicoes, 3)) return 3;
    if (matrizPosicoes[2][2] == 100 && casaLivre(matrizPosicoes, 1)) return 1;

    if(casaLivre(matrizPosicoes, 1)) return 1;
    if(casaLivre(matrizPosicoes, 3)) return 3;
    if(casaLivre(matrizPosicoes, 7)) return 7;
    if(casaLivre(matrizPosicoes, 9)) return 9;

    if(casaLivre(matrizPosicoes, 2)) return 2;
    if(casaLivre(matrizPosicoes, 4)) return 4;
    if(casaLivre(matrizPosicoes, 6)) return 6;
    if(casaLivre(matrizPosicoes, 8)) return 8;

    return 0;
}