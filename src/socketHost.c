#include <stdio.h>>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma coment(lib, "ws2_32.lib")
int conectarServidor(){
    WSADATA wsa;
    SOCKET idSocket;
    struct sockaddr_in enderecoServidor;

    if(WSAStartup(MAKEWORD(2,2), &wsa) != 0){
        printf("Falha ao inicializar na rede.\n", WSAGetLastError());
        return -1;
    }

    idSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (idSocket == INVALID_SOCKET){
        printf("Erro ao criar o socket. \n");
        WSACleanup();
        return -1;
    }

    enderecoServidor.sin_family = AF_INET;
    enderecoServidor.sin_port = htons(8080);
    enderecoServidor.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(idSocket, (struct sockaddr *)&enderecoServidor, sizeof(enderecoServidor)) < 0){
        printf("Erro ao conectar ao servidor. \n");
        return -1;
    }
    printf("Conectado ao servidor.\n");
    return idSocket;
    
}