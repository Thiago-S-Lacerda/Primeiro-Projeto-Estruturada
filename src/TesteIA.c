/ Regra 3

    if(casaLivre(matrizPosicoes, 5)){
        return 5;
    }

// Regra 4

    if (matrizPosicoes[0][0] == 100){
        if(casaLivre(matrizPosicoes, 9)){
            return 9;
        }
    }
    if (matrizPosicoes[0][2] == 100){
        if(casaLivre(matrizPosicoes, 7)){
            return 7;
        }
    }
    if (matrizPosicoes[2][0] == 100){
        if(casaLivre(matrizPosicoes, 3)){
            return 3;
        }
    }
    if (matrizPosicoes == 1){
        if(casaLivre(matrizPosicoes, 1)){
            return 1;
        }
    }

// Regra 5

    if(casaLivre(matrizPosicoes, 1)){
        return 1;
    }
    if(casaLivre(matrizPosicoes, 3)){
        return 3;
    }
    if(casaLivre(matrizPosicoes, 7)){
        return 7;
    }
    if(casaLivre(matrizPosicoes, 9)){
        return 9;
    }

// Regra 6

    int laterais[4] = {2,4,6,8};
    int livres[4];
    int qtd = 0;
    int i;

    for(i = 0; i < 4; i++){
        if(casaLivre(matrizPosicoes, laterais[i])){
            livres[qtd] = laterais[i];
            qtd++;
        }
    }
    if(qtd > 0){
        return livres[rand() % qtd];
    }