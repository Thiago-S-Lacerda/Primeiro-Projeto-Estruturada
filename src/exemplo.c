#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes_thiago.h"

int main() {
	setlocale(LC_ALL, "Portuguese");
	int posicoes[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	char tabuleiro[3][3] = {{'_','_','_'}, {'_','_','_'}, {' ',' ',' '}};
	int resultado;
	
	printf("Exemplo das posições:\n");
	printf("\t_1_|_2_|_3_\n");
	printf("\t_4_|_5_|_6_\n");
	printf("\t 7 | 8 | 9 \n");
	system("pause");
	printf("\033[2J\033[H");

	do {
		desenha(posicoes, tabuleiro);
        marcaJogada(posicoes, tabuleiro, "Thiago", "Caio");

		resultado = temVencedor(posicoes, "Thiago", "Caio");
		if (resultado == 2) {
			desenha(posicoes, tabuleiro);
			printf("%s venceu!!", "Caio");
			break;
		} else if (resultado == 1) {
			desenha(posicoes, tabuleiro);
			printf("%s venceu!!", "Thiago");
			break;
		}
	} while(1);
	
	return 0;
}