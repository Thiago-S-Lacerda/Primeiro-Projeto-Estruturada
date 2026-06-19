#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes_thiago.h"

int main() {
	setlocale(LC_ALL, "Portuguese");
	int matrizEscolha[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	char matrizResposta[3][3] = {{'_','_','_'}, {'_','_','_'}, {' ',' ',' '}};
	
	printf("Exemplo das posições:\n");
	printf("\t_1_|_2_|_3_\n");
	printf("\t_4_|_5_|_6_\n");
	printf("\t 7 | 8 | 9 \n");
	system("pause");
	printf("\033[2J\033[H");

	do {
		desenha(matrizEscolha, matrizResposta);
        marcaJogada(matrizEscolha, matrizResposta, "Thiago", "Caio");
	} while(1);
	
	return 0;
}