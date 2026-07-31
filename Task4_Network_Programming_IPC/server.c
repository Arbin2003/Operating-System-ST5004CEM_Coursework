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
    free(arg);

    char buffer[BUFFER_SIZE];
    char username[50];
    char password[50];

    memset(buffer, 0, sizeof(buffer));

    int bytes = recv(clientSocket, buffer, BUFFER_SIZE, 0);

    if (bytes <= 0)
    {
        printf("Client disconnected before authentication.\n");
        close(clientSocket);
        return NULL;
    }

    sscanf(buffer, "%49s %49s", username, password);

    if (strcmp(username, USERNAME) == 0 &&
        strcmp(password, PASSWORD) == 0)
    {
        char success[] = "Login successful";
        send(clientSocket, success, strlen(success) + 1, 0);

        printf("Client authenticated.\n");

        while (1)
        {
            memset(buffer, 0, sizeof(buffer));

            bytes = recv(clientSocket, buffer, BUFFER_SIZE, 0);

            if (bytes <= 0)
            {
                printf("Client disconnected.\n");
                break;
            }

            printf("Client: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0)
            {
                printf("Client requested to close the connection.\n");
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
        send(clientSocket, fail, strlen(fail) + 1, 0);

        printf("Authentication failed.\n");
    }

    close(clientSocket);

    printf("Waiting for client...\n");

    return NULL;
}

int main()
{
    int serverSocket;
    struct sockaddr_in serverAddress;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

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
        close(serverSocket);
        return 1;
    }

    if (listen(serverSocket, 5) < 0)
    {
        perror("Listen failed");
        close(serverSocket);
        return 1;
    }

    printf("=====================================\n");
    printf("TCP Server Started\n");
    printf("Server running on port %d...\n", PORT);
    printf("Waiting for client...\n");
    printf("=====================================\n");

    while (1)
    {
        int *clientSocket = malloc(sizeof(int));

        if (clientSocket == NULL)
        {
            perror("Memory allocation failed");
            continue;
        }

        *clientSocket = accept(serverSocket, NULL, NULL);

        if (*clientSocket < 0)
        {
            perror("Accept failed");
            free(clientSocket);
            continue;
        }

        printf("Client connected.\n");

        pthread_t thread;

        if (pthread_create(&thread, NULL, handleClient, clientSocket) != 0)
        {
            perror("Thread creation failed");
            close(*clientSocket);
            free(clientSocket);
            continue;
        }

        pthread_detach(thread);
    }

    close(serverSocket);

    return 0;
}
