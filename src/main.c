/*
	* Título: Jogo da Velha
	* Autores: Caio Paiva, Thiago Lacerda
	* Data de Criação: 11/06/2026
	* Última Alteração: 29/06/2026
	* Descrição: Projeto de Programação Estruturada. Desenvolvimento de um Jogo da Velha em linguagem C
 */

#include "Partida.h"

int main() {
	char nomeJogador1[50], nomeJogador2[50];
	char simboloJ1, simboloJ2;
	int turno; 
	int posicoesDeEscolha[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	char tabuleiro[3][3] = {{'_','_','_'}, {'_','_','_'}, {' ',' ',' '}};

	configuraJogadores(nomeJogador1, nomeJogador2, &simboloJ1, &simboloJ2, &turno);
	inicia(posicoesDeEscolha, tabuleiro, &turno, nomeJogador1, nomeJogador2, simboloJ1, simboloJ2);

	return 0;
}
