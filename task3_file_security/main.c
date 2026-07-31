#include <stdio.h>
#include "auth.h"
#include "file_ops.h"
#include "logger.h"
#include "encryption.h"


int main()
{

    printf("=================================\n");
    printf(" Secure File Management System\n");
    printf("=================================\n");


    if(login() == 0)
    {
        return 1;
    }


    int choice;


    while(1)
    {

        printf("\n========== MENU ==========\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Write File\n");
        printf("4. Delete File\n");
        printf("5. Change Permission\n");
        printf("6. Encrypt File\n");
        printf("7. Decrypt File\n");
        printf("8. Exit\n");


        printf("Enter choice: ");
        scanf("%d",&choice);



        switch(choice)
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
                encryptFile();
                break;


            case 7:
                decryptFile();
                break;


            case 8:

                printf("Exiting system...\n");
                return 0;


            default:

                printf("Invalid option.\n");

        }

    }


    return 0;
}
