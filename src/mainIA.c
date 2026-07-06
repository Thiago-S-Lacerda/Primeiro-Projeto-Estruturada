/*
	* Título: Jogo da Velha VS "IA"
	* Autores: Caio Paiva, Thiago Lacerda
	* Data de Criação: 01/07/2026
	* Última Alteração: 06/07/2026
	* Descrição: Projeto de Programação Estruturada. Desenvolvimento de um Jogo da Velha em linguagem C. Versão IA
 */

#include "Partida.h"

int main() {
	char nomeJogador1[50], nomeJogador2[50];
	char simboloJ1, simboloJ2, simboloIA;
	int turno, modoDeJogo; 

	configuraJogadores(nomeJogador1, nomeJogador2, &simboloJ1, &simboloJ2, &simboloIA, &turno, MODO_IA);
	inicia(&turno, nomeJogador1, nomeJogador2, simboloJ1, simboloJ2, simboloIA, MODO_IA);

	return 0;
}
