#include <stdio.h>
#include "auth.h"
#include "file_ops.h"

int main()
{
    int choice;

    printf("=====================================\n");
    printf(" Secure File Management System\n");
    printf("=====================================\n\n");

    if (!login())
    {
        printf("Access denied.\n");
        return 1;
    }

    while (1)
    {
        printf("\n========== MENU ==========\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Write File\n");
        printf("4. Delete File\n");
        printf("5. Change File Permission\n");
        printf("6. Exit\n");
        printf("==========================\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createFile();
                break;

            case 2:
                readFile();
                break;

            case 3:
                writeFile();
                break;

            case 4:
                deleteFile();
                break;

            case 5:
                changePermission();
                break;

            case 6:
                printf("Exiting system...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
