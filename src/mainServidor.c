/*
	* Título: Jogo da Velha Remoto
	* Autores: Caio Paiva, Thiago Lacerda
	* Data de Criação: 05/07/2026
	* Última Alteração: 06/07/2026
	* Descrição: Projeto de Programação Estruturada. Desenvolvimento de um Jogo da Velha em linguagem C. Versão socket servidor
 */

#include "Partida.h"

int main() {
	char nomeJogador1[50], nomeJogador2[50];
	char simboloJ1, simboloJ2, simboloIA;
	int turno = 1, modoDeJogo; 

	inicia(&turno, nomeJogador1, nomeJogador2, simboloJ1, simboloJ2, simboloIA, MODO_SERVIDOR);

	return 0;
}
