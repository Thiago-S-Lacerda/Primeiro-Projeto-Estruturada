#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "JogadorRemoto.h"

#define PORTA 8080
#define IP "127.0.0.1"

SOCKET conecta() {
    WSADATA wsadata;

    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        printf("Falha na inicialização\n");
        exit(EXIT_FAILURE);
    }

    SOCKET socketCliente;
    struct sockaddr_in alvoComunicacao;

    socketCliente = socket(AF_INET, SOCK_STREAM, 0);
    if (socketCliente == INVALID_SOCKET) {
        printf("Erro na criação do socket\n");
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    alvoComunicacao.sin_family = AF_INET;
    alvoComunicacao.sin_port = htons(PORTA);
    alvoComunicacao.sin_addr.S_un.S_addr = inet_addr(IP); 

    if (connect(socketCliente, (struct sockaddr*)&alvoComunicacao, sizeof(alvoComunicacao)) < 0) {
        printf("Erro na conexão\n");
        closesocket(socketCliente);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao Servidor!\n");
    return socketCliente;
}

SOCKET ligarServidor(){
    WSADATA wsa;
    SOCKET idSocket;
    struct sockaddr_in enderecoServidor;
    socklen_t endereco_len = sizeof(enderecoServidor);

    if(WSAStartup(MAKEWORD(2,2), &wsa) != 0){
        printf("Falha ao inicializar na rede.\n", WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    idSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (idSocket == INVALID_SOCKET){
        printf("Erro ao criar o socket. \n");
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    enderecoServidor.sin_family = AF_INET;
    enderecoServidor.sin_port = htons(PORTA);
    enderecoServidor.sin_addr.S_un.S_addr = inet_addr(IP);

    if (bind(idSocket, (struct sockaddr *)&enderecoServidor, sizeof(enderecoServidor)) < 0){
        printf("Erro ao dar bind.\n");
        closesocket(idSocket);
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    
    if (listen(idSocket, 1) < 0) {
        printf("Erro no listen.\n");
        closesocket(idSocket);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    return idSocket;
}

void aceitaCliente(SOCKET sockServidor, SOCKET *sockCliente) {
    struct sockaddr_in enderecoServidor;
    socklen_t endereco_len = sizeof(enderecoServidor);

    printf("Esperando conexão do outro jogador...\n");

    *sockCliente = accept(sockServidor, (struct sockaddr *)&enderecoServidor, &endereco_len);
    if (*sockCliente < 0) {
        perror("Erro no accept\n");
        closesocket(sockServidor);
        WSACleanup();
        exit(EXIT_FAILURE);
    }
}

void recebeMensagem(SOCKET sock, int *jogada) {
    int posicao;

    printf("Esperando jogada do oponente...\n");
    int bytes = recv(sock, (char*)&posicao, sizeof(posicao), 0);
    if (bytes <= 0) {
        printf("Cliente desconectou!\n");
        closesocket(sock);
        WSACleanup();
        exit(EXIT_FAILURE);
    } else {
        *jogada = posicao;
    }
}

void enviaJogada(SOCKET sock, int *jogada) {
    int posicao = *jogada;
    send(sock, (char*)&posicao, sizeof(posicao), 0);
}

void jogaRemoto(int *posicaoEscolhida, int *turno_jogador, Jogador remoto, SOCKET sock) {
    setlocale(LC_ALL, "Portuguese");

    if (remoto == HOST) {
        if (*turno_jogador == 1) {
            printf("Sua vez!!\n");
            printf("Digite a posição que você quer jogar: ");
            scanf("%d", posicaoEscolhida);
            enviaJogada(sock, posicaoEscolhida);
        } else if (*turno_jogador == 2) {
            printf("Vez do cliente!!\n");
            recebeMensagem(sock, posicaoEscolhida);
        }
    } else {
        if (*turno_jogador == 1) {
            printf("Vez do host!!\n");
            recebeMensagem(sock, posicaoEscolhida);
        } else if (*turno_jogador == 2) {
            printf("Sua vez!!\n");
            printf("Digite a posição que você quer jogar: ");
            scanf("%d", posicaoEscolhida);
            enviaJogada(sock, posicaoEscolhida);
        }
    }
}