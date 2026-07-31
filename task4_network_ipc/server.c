#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include "common.h"

void *handleClient(void *arg)
{
    int clientSocket = *(int *)arg;
    char buffer[BUFFER_SIZE];

    char username[50];
    char password[50];

    memset(buffer, 0, BUFFER_SIZE);

    recv(clientSocket, buffer, BUFFER_SIZE, 0);

    sscanf(buffer, "%s %s", username, password);

    if (strcmp(username, USERNAME) == 0 &&
        strcmp(password, PASSWORD) == 0)
    {
        char success[] = "Login successful";

        send(clientSocket, success, strlen(success) + 1, 0);

        printf("Client authenticated\n");

        while (1)
        {
            memset(buffer, 0, BUFFER_SIZE);

            int bytes = recv(clientSocket, buffer, BUFFER_SIZE, 0);

            if (bytes <= 0)
                break;

            printf("Client: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0)
            {
                printf("Client disconnected\n");
                break;
            }

            char reply[] = "Message received by server";

            send(clientSocket,
                 reply,
                 strlen(reply) + 1,
                 0);
        }
    }
    else
    {
        char fail[] = "Login failed";

        send(clientSocket,
             fail,
             strlen(fail) + 1,
             0);
    }

    close(clientSocket);
    free(arg);

    return NULL;
}


int main()
{
    int serverSocket;
    struct sockaddr_in serverAddress;

    serverSocket = socket(AF_INET,
                          SOCK_STREAM,
                          0);

    if (serverSocket < 0)
    {
        perror("Socket failed");
        return 1;
    }


    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;


    if (bind(serverSocket,
             (struct sockaddr *)&serverAddress,
             sizeof(serverAddress)) < 0)
    {
        perror("Bind failed");
        return 1;
    }


    listen(serverSocket, 5);


    printf("Server running on port %d...\n", PORT);


    while (1)
    {
        int *clientSocket = malloc(sizeof(int));

        *clientSocket = accept(serverSocket,
                               NULL,
                               NULL);


        pthread_t thread;

        pthread_create(&thread,
                       NULL,
                       handleClient,
                       clientSocket);

        pthread_detach(thread);
    }


    close(serverSocket);

    return 0;
}
