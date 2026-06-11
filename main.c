#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	int jogador = 1, posicao, i, j, somaLinhas = 0, somaColunas = 0;
	int matrizEscolha[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	char matrizResposta[3][3] = {{'_','_','_'}, {'_','_','_'}, {' ',' ',' '}};
	
	printf("Exemplo das posições:\n");
	printf("\t_1_|_2_|_3_\n");
	printf("\t_4_|_5_|_6_\n");
	printf("\t 7 | 8 | 9 \n");
	system("pause");
	system("cls");
	printf("\n");
	printf("\t___|___|___\n");
	printf("\t___|___|___\n");
	printf("\t   |   |   \n");
	
	do {
		if (jogador == 1) {
			printf("Digite a posição que você quer jogar: ");
			scanf("%d", &posicao);
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					if (matrizEscolha[i][j] == posicao) {
						matrizEscolha[i][j] = 100;
						matrizResposta[i][j] = 'X';
					}
				}
			}
			jogador = 2;
		} else if (jogador == 2) {
			printf("Digite a posição que você quer jogar: ");
			scanf("%d", &posicao);
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					if (matrizEscolha[i][j] == posicao) {
						matrizEscolha[i][j] = 400;
						matrizResposta[i][j] = 'O';
					}
				}
			}
			jogador = 1;
		} else {
			break;
		}
        
		system("cls");
		printf("\n");
		printf("\t_%c_|_%c_|_%c_\n", matrizResposta[0][0], matrizResposta[0][1], matrizResposta[0][2]);
		printf("\t_%c_|_%c_|_%c_\n", matrizResposta[1][0], matrizResposta[1][1], matrizResposta[1][2]);
		printf("\t %c | %c | %c \n", matrizResposta[2][0], matrizResposta[2][1], matrizResposta[2][2]);
		
		for (i = 0; i < 3; i++) {
			somaLinhas = 0;
			somaColunas = 0;
				for (j = 0; j < 3; j++) {
					somaLinhas += matrizEscolha[i][j];
					somaColunas += matrizEscolha[j][i];
					if (somaLinhas == 300 || somaColunas == 300) {
						printf("O jogador do X ganhou!!");
						jogador = 3;
						break;
					} else if (somaLinhas == 1200 || somaColunas == 1200) {
						printf("O jogador da O ganhou!!");
						jogador = 3;
						break;
					}
				}
			}
	} while(1);
	
	return 0;
}