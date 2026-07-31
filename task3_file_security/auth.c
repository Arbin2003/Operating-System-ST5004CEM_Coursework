#include <stdio.h>
#include <string.h>
#include "auth.h"

int login()
{
    char username[50];
    char password[50];

    printf("========== Login ==========\n");

    printf("Username: ");
    scanf("%49s", username);

    printf("Password: ");
    scanf("%49s", password);

    if (strcmp(username, USERNAME) == 0 &&
        strcmp(password, PASSWORD) == 0)
    {
        printf("\nLogin successful!\n");
        return 1;
    }

    printf("\nInvalid username or password.\n");
    return 0;
}
