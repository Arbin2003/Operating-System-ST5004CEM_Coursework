#include <stdio.h>
#include "memory.h"

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);

    printf("=========================================\n");
    printf("Task 2 - Memory Management Simulation\n");
    printf("=========================================\n");

    printf("\nPage Reference String:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", pages[i]);

    printf("\n");

    fifo(pages, n, MAX_FRAMES);

    lru(pages, n, MAX_FRAMES);

    printf("\nSimulation Completed Successfully.\n");

    return 0;
}
