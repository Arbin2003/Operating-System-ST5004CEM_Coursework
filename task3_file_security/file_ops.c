#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_ops.h"
#include "logger.h"

void createFile()
{
    char filename[100];

    printf("Enter filename to create: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Unable to create file.\n");
        return;
    }

    fclose(file);

    logAction("CREATE", filename);

    printf("File created successfully.\n");
}


void readFile()
{
    char filename[100];
    char ch;

    printf("Enter filename to read: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("File not found.\n");
        return;
    }

    printf("\n--- File Content ---\n");

    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(file);

    logAction("READ", filename);
}


void writeFile()
{
    char filename[100];
    char content[500];

    printf("Enter filename to write: ");
    scanf("%99s", filename);

    getchar();

    printf("Enter content: ");
    fgets(content, sizeof(content), stdin);

    FILE *file = fopen(filename, "a");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    fprintf(file, "%s", content);

    fclose(file);

    logAction("WRITE", filename);

    printf("Content written successfully.\n");
}


void deleteFile()
{
    char filename[100];

    printf("Enter filename to delete: ");
    scanf("%99s", filename);

    if (remove(filename) == 0)
    {
        logAction("DELETE", filename);
        printf("File deleted successfully.\n");
    }
    else
    {
        printf("Unable to delete file.\n");
    }
}


void changePermission()
{
    char filename[100];
    int permission;

    printf("Enter filename: ");
    scanf("%99s", filename);

    printf("Enter permission (example 644): ");
    scanf("%d", &permission);

    if (chmod(filename, permission) == 0)
    {
        logAction("CHMOD", filename);
        printf("Permissions changed successfully.\n");
    }
    else
    {
        printf("Permission change failed.\n");
    }
}
