#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <stdio.h>

#define PORT 55002
#define BUFFER_SIZE 100

int main() {
    WSADATA wsdata;

    if (WSAStartup(MAKEWORD(2, 2), &wsdata) != 0) {
        printf("Fail to initiate ws_32.dll \n\n");
        return 0;
    }

    printf("Success to initiate ws_32.dll\n\n");

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    SOCKADDR_IN serverAddress;
    ZeroMemory(&serverAddress, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);

    
    serverAddress.sin_addr.s_addr = inet_addr("192.168.1.106");
//converts dotted ip into NBO
    if ((connect(clientSocket, (SOCKADDR*)(&serverAddress), sizeof(serverAddress)) != 0)) {
        printf("Fail to connect.\n\n");// you can also use SOCKET_ERROR OR INVALID_SOCKET values to check if there is error in socket system calls. we can call function WSAGetLastError() to get last error.
        return 0;
    }

    printf("connected!!! \n\n");

    char toServer[BUFFER_SIZE];

    strcpy(toServer, "Hello Server!!! I'm client!");

    send(clientSocket, toServer, strlen(toServer) + 1, 0);

    printf("Data to server : %s\n\n", toServer);

    char fromServer[BUFFER_SIZE + 1];

    recv(clientSocket, fromServer, BUFFER_SIZE, 0);

    printf("received data from server : %s\n", fromServer);

    closesocket(clientSocket);

    WSACleanup();
    printf("Exit ws_32.dll\n\n");
    return 0;
}
