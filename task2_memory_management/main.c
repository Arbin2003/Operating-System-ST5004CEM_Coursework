#include <stdio.h>
#include "memory.h"

int main()
{
    int pages[MAX_PAGES];
    int frames;
    int n;
    int pageSize;

    printf("========================================\n");
    printf("   Memory Management Simulation\n");
    printf("========================================\n");


    // Configurable page size
    printf("\nEnter page size: ");
    scanf("%d", &pageSize);

    if (pageSize <= 0)
    {
        printf("Invalid page size.\n");
        return 1;
    }


    // Number of memory frames
    printf("Enter number of page frames (1-%d): ", MAX_FRAMES);
    scanf("%d", &frames);


    if (frames < 1 || frames > MAX_FRAMES)
    {
        printf("Invalid number of frames.\n");
        return 1;
    }


    // Number of page references
    printf("Enter number of page references (1-%d): ", MAX_PAGES);
    scanf("%d", &n);


    if (n < 1 || n > MAX_PAGES)
    {
        printf("Invalid number of page references.\n");
        return 1;
    }


    printf("Enter the page reference string:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }


    printf("\n========================================\n");
    printf("Memory Configuration\n");
    printf("========================================\n");

    printf("Page Size           : %d\n", pageSize);
    printf("Number of Frames    : %d\n", frames);
    printf("Page References     : %d\n", n);



    printf("\n========================================\n");
    printf("FIFO Page Replacement\n");
    printf("========================================\n");

    fifo(pages, n, frames);



    printf("\n========================================\n");
    printf("LRU Page Replacement\n");
    printf("========================================\n");

    lru(pages, n, frames);



    printf("\nSimulation completed successfully.\n");


    return 0;
}
