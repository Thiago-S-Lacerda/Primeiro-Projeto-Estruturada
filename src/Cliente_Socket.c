#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define PORTA 8080

SOCKET cliente_socket() {
    WSADATA wsadata;

    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        printf("Falha na inicialização\n");
        return 1;
    }

    SOCKET socketCliente;
    struct sockaddr_in alvoComunicacao;

    socketCliente = socket(AF_INET, SOCK_STREAM, 0);
    if (socketCliente == INVALID_SOCKET) {
        printf("Erro na criação do socket\n");
        exit(EXIT_FAILURE);
    }

    alvoComunicacao.sin_family = AF_INET;
    alvoComunicacao.sin_port = htons(PORTA);
    alvoComunicacao.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); 

    if (connect(socketCliente, (struct sockaddr*)&alvoComunicacao, sizeof(alvoComunicacao)) < 0) {
        printf("Erro na conexão\n");
        closesocket(socketCliente);
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao Servidor!\n");
    return socketCliente;
}