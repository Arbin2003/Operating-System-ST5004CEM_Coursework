#include <stdio.h>
#include <stdlib.h>
#include "encryption.h"
#include "logger.h"

#define KEY 5


void encryptFile()
{
    char filename[100];

    printf("Enter filename to encrypt: ");
    scanf("%99s", filename);


    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("File not found.\n");
        return;
    }


    FILE *temp = fopen("encrypted.tmp", "w");


    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        fputc(ch + KEY, temp);
    }


    fclose(file);
    fclose(temp);


    remove(filename);
    rename("encrypted.tmp", filename);


    logAction("ENCRYPT", filename);

    printf("File encrypted successfully.\n");
}



void decryptFile()
{
    char filename[100];

    printf("Enter filename to decrypt: ");
    scanf("%99s", filename);


    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("File not found.\n");
        return;
    }


    FILE *temp = fopen("decrypted.tmp", "w");


    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        fputc(ch - KEY, temp);
    }


    fclose(file);
    fclose(temp);


    remove(filename);
    rename("decrypted.tmp", filename);


    logAction("DECRYPT", filename);

    printf("File decrypted successfully.\n");
}
