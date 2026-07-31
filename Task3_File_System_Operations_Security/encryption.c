#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "encryption.h"
#include "logger.h"

#define KEY 5

void encryptFile()
{
    char filename[100];

    printf("Enter filename to encrypt: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        perror("Reason");
        return;
    }

    FILE *temp = fopen("encrypted.tmp", "wb");

    if (temp == NULL)
    {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    int ch;

    while ((ch = fgetc(file)) != EOF)
    {
        fputc(ch + KEY, temp);
    }

    fclose(file);
    fclose(temp);

    if (remove(filename) != 0)
    {
        perror("Unable to remove original file");
        return;
    }

    if (rename("encrypted.tmp", filename) != 0)
    {
        perror("Unable to rename temporary file");
        return;
    }

    logAction("ENCRYPT", filename);

    printf("File encrypted successfully.\n");
}

void decryptFile()
{
    char filename[100];

    printf("Enter filename to decrypt: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        perror("Reason");
        return;
    }

    FILE *temp = fopen("decrypted.tmp", "wb");

    if (temp == NULL)
    {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    int ch;

    while ((ch = fgetc(file)) != EOF)
    {
        fputc(ch - KEY, temp);
    }

    fclose(file);
    fclose(temp);

    if (remove(filename) != 0)
    {
        perror("Unable to remove original file");
        return;
    }

    if (rename("decrypted.tmp", filename) != 0)
    {
        perror("Unable to rename temporary file");
        return;
    }

    logAction("DECRYPT", filename);

    printf("File decrypted successfully.\n");
}
