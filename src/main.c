#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char nomeJogador1[50];
char nomeJogador2[50];
char simboloJ1, simboloJ2;
	
int jogador = 1, posicao, i, j, somaLinhas = 0, somaColunas = 0;
int matrizEscolha[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
char matrizResposta[3][3] = {{'_','_','_'}, {'_','_','_'}, {' ',' ',' '}};
int somaDiagonal1, somaDiagonal2;

void configuraJogadores();
void inicia();

int main(){
	setlocale(LC_ALL, "Portuguese");

	configuraJogadores();
	inicia();

	return 0;
}
