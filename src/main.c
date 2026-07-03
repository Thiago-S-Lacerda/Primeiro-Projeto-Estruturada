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
	char simboloJ1, simboloJ2, simboloIA;
	int turno, modoDeJogo; 

	configuraJogadores(nomeJogador1, nomeJogador2, &simboloJ1, &simboloJ2, &simboloIA, &turno, &modoDeJogo);
	inicia(&turno, nomeJogador1, nomeJogador2, simboloJ1, simboloJ2, simboloIA, modoDeJogo);

	return 0;
}
