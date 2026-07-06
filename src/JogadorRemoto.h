#ifndef _JogadorRemoto_H
#define _JogadorRemoto_H
#include <winsock2.h>

typedef enum {
    HOST,
    CLIENTE
} Jogador;

SOCKET conecta();

SOCKET ligarServidor();

void aceitaCliente(SOCKET sockServidor, SOCKET *sockCliente);

void recebeMensagem(SOCKET sock, int *jogada);

void enviaJogada(SOCKET sock, int *jogada);

void jogaRemoto(int *posicaoEscolhida, int *turno_jogador, Jogador remoto, SOCKET sock);

#endif