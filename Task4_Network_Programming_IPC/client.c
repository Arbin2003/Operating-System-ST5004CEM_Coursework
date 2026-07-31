#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "common.h"


int main()
{
    int socketFD;

    struct sockaddr_in serverAddress;

    char username[50];
    char password[50];

    char buffer[BUFFER_SIZE];


    socketFD = socket(AF_INET,
                      SOCK_STREAM,
                      0);


    if (socketFD < 0)
    {
        perror("Socket failed");
        return 1;
    }


    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);


    inet_pton(AF_INET,
              "127.0.0.1",
              &serverAddress.sin_addr);



    if (connect(socketFD,
                (struct sockaddr *)&serverAddress,
                sizeof(serverAddress)) < 0)
    {
        perror("Connection failed");
        return 1;
    }


    printf("Username: ");
    scanf("%49s", username);


    printf("Password: ");
    scanf("%49s", password);



    char loginData[100];

    snprintf(loginData,
             sizeof(loginData),
             "%s %s",
             username,
             password);


    send(socketFD,
         loginData,
         strlen(loginData) + 1,
         0);



    memset(buffer, 0, BUFFER_SIZE);


    recv(socketFD,
         buffer,
         BUFFER_SIZE,
         0);


    printf("Server: %s\n", buffer);



    if (strcmp(buffer, "Login successful") == 0)
    {
        while (1)
        {
            printf("Enter message (exit to quit): ");

            scanf(" %[^\n]", buffer);


            send(socketFD,
                 buffer,
                 strlen(buffer) + 1,
                 0);


            if (strcmp(buffer, "exit") == 0)
                break;


            memset(buffer, 0, BUFFER_SIZE);


            recv(socketFD,
                 buffer,
                 BUFFER_SIZE,
                 0);


            printf("Server: %s\n", buffer);
        }
    }


    close(socketFD);

    return 0;
}
