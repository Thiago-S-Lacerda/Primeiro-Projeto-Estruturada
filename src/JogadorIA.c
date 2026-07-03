#include <stdio.h>
#include <stdlib.h>

int casaLivre(int matrizPosicoes[][3], int numeroProcurado){
    int linha[9] = {0,0,0,1,1,1,2,2,2};
    int coluna[9] = {0,1,2,0,1,2,0,1,2};

    int p = numeroProcurado - 1;
    int i = linha[p];
    int j = coluna[p];
    
    if(matrizPosicoes[i][j] == numeroProcurado) {
        return 1;
    } else {
        return 0;
    }
    
}

int possiveisGanhos(int matrizPosicoes[][3]) {
    int i, j, somaLinhas, somaColunas;
    int countPossiveisGanhos = 0;
    for (i = 0; i < 3; i++) {
        somaLinhas = 0;
        somaColunas = 0;
        for (j = 0; j < 3; j++) {
            somaLinhas += matrizPosicoes[i][j];
            somaColunas += matrizPosicoes[j][i];
            if (somaLinhas > 200 && somaLinhas < 400) {
                countPossiveisGanhos += 1;
            }
            if (somaColunas > 200 && somaColunas < 400) {
                countPossiveisGanhos += 1;
            }
        }
	}

    int somaDiagonalP = 0, somaDiagonalS = 0;
    for (i = 0; i < 3; i++) {
        somaDiagonalP += matrizPosicoes[i][i];
        somaDiagonalS += matrizPosicoes[i][2-i];
	}
    if (somaDiagonalP > 200 && somaDiagonalP < 400) {
        countPossiveisGanhos += 1;
    }
    if (somaDiagonalS > 200 && somaDiagonalS < 400) {
        countPossiveisGanhos += 1;
    }
    if (countPossiveisGanhos == 2) {
        return 1;
    } else {
        return 0;
    }
}

int regra1IA(int matrizPosicoes[][3]) {
    int i, l, c;
    int contaJ2 = 0, contaIA = 0, livres = 0, alvo = 0;
    int contas_IA[3][3];
    int contas_J2[3][3];
    
    for(l = 0; l < 3; l++){
        contaIA = 0;
        contaJ2 = 0;
        livres = 0;
        for(c = 0; c < 3; c++){
            if(matrizPosicoes[l][c] == 100){
                contaIA++;
            }
            else if(matrizPosicoes[l][c] == 400){
                contaJ2++;
            } 
            else {
                livres++;
                alvo = matrizPosicoes[l][c];
            }
        }
        contas_IA[l][0] = contaIA;
        contas_IA[l][1] = livres;
        contas_IA[l][2] = alvo;
        contas_J2[l][0] = contaJ2;
        contas_J2[l][1] = livres;
        contas_J2[l][2] = alvo;
    }
    for (i = 0; i < 3; i++) {
        contaIA = contas_IA[i][0];
        livres = contas_IA[i][1];
        alvo = contas_IA[i][2];
        if (livres == 1 && contaIA == 2) {
            return alvo;
        }
    }
    for (i = 0; i < 3; i++) {
        contaJ2 = contas_J2[i][0];
        livres = contas_J2[i][1];
        alvo = contas_J2[i][2];
        if (livres == 1 && contaJ2 == 2) {
            return alvo;
        }
    }

    for(c = 0; c < 3; c++){
        contaIA = 0;
        contaJ2 = 0;
        livres = 0;
        alvo = 0;
        for (l = 0; l < 3; l++){
            if (matrizPosicoes[l][c] == 100) {
                contaIA++;
            }
            else if (matrizPosicoes[l][c] == 400) {
                contaJ2++;
            }
            else {
                livres++;
                alvo = matrizPosicoes[l][c]; 
            }
        }
        contas_IA[c][0] = contaIA;
        contas_IA[c][1] = livres;
        contas_IA[c][2] = alvo;
        contas_J2[c][0] = contaJ2;
        contas_J2[c][1] = livres;
        contas_J2[c][2] = alvo;
    }
    for (i = 0; i < 3; i++) {
        contaIA = contas_IA[i][0];
        livres = contas_IA[i][1];
        alvo = contas_IA[i][2];
        if (livres == 1 && contaIA == 2) {
            return alvo;
        }
    }
    for (i = 0; i < 3; i++) {
        contaJ2 = contas_J2[i][0];
        livres = contas_J2[i][1];
        alvo = contas_J2[i][2];
        if (livres == 1 && contaJ2 == 2) {
            return alvo;
        }
    }

    int contaJ2_d1 = 0, contaIA_d1 = 0, livres_d1 = 0, alvo_d1;
    for(i = 0; i < 3; i++){
        if(matrizPosicoes[i][i] == 100) {
            contaIA_d1++;
        } 
        else if (matrizPosicoes[i][i] == 400) {
            contaJ2_d1++;
        } 
        else {
            livres_d1++;
            alvo_d1 = matrizPosicoes[i][i];
        }
    }
    if(livres_d1 == 1 && (contaIA_d1 == 2 || contaJ2_d1 == 2)){
        return alvo_d1;
    }
    int contaJ2_d2 = 0, contaIA_d2 = 0, livres_d2 = 0, alvo_d2;
    for(i = 0; i < 3; i++){
        if(matrizPosicoes[i][2 - i] == 100) {
            contaIA_d2++;
        } 
        else if (matrizPosicoes[i][2 - i] == 400) {
            contaJ2_d2++;
        }
        else {
            livres_d2++;
            alvo_d2 = matrizPosicoes[i][2 - i];
        }
    }
    if(livres_d2 && (contaIA_d2 == 2 || contaJ2_d2 == 2)){
        return alvo_d2;
    }

    return 0;
}
int regra2IA(int matrizPosicoes[][3]) {
    int i, j, posicao = 1, valorAnterior;
    int resultado;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if (matrizPosicoes[i][j] != 100 && matrizPosicoes[i][j] != 400){
                valorAnterior = matrizPosicoes[i][j];
                matrizPosicoes[i][j] = 100;
                resultado = possiveisGanhos(matrizPosicoes);
                matrizPosicoes[i][j] = valorAnterior;
                if(resultado == 1) {
                    return posicao;
                }
            }
            posicao += 1;
        }
    }
    return 0;
}


int pensaIA(int matrizPosicoes[][3]) {
    printf("\nIA pensando na jogada...\n");

    int regra1 = regra1IA(matrizPosicoes);
    if(regra1 != 0) {
        return regra1;
    }

    int regra2 = regra2IA(matrizPosicoes);
    if(regra2 != 0) {
        return regra2;
    }

    if(casaLivre(matrizPosicoes, 5) != 0){
       return 5;
    }
    if (matrizPosicoes[0][0] == 400 && casaLivre(matrizPosicoes, 9)) return 9;
    if (matrizPosicoes[0][2] == 400 && casaLivre(matrizPosicoes, 7)) return 7;
    if (matrizPosicoes[2][0] == 400 && casaLivre(matrizPosicoes, 3)) return 3;
    if (matrizPosicoes[2][2] == 400 && casaLivre(matrizPosicoes, 1)) return 1;
    
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