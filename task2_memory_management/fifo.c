#include <stdio.h>
#include "memory.h"

void fifo(int pages[], int n, int frames)
{
    int frame[MAX_FRAMES];
    int pointer = 0;
    int hits = 0, faults = 0;

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\n%-8s %-20s %-10s\n", "Page", "Frames", "Status");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        int found = 0;

        /* Check if page is already in memory */
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                hits++;
                break;
            }
        }

        /* Page fault */
        if (!found)
        {
            frame[pointer] = pages[i];
            pointer = (pointer + 1) % frames;
            faults++;
        }

        printf("%-8d ", pages[i]);

        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        if (found)
            printf("   Hit");
        else
            printf("   Fault");

        printf("\n");
    }

    printf("\n--------------- FIFO Statistics ---------------\n");
    printf("Total Page References : %d\n", n);
    printf("Page Hits             : %d\n", hits);
    printf("Page Faults           : %d\n", faults);
    printf("Hit Ratio             : %.2f\n", (float)hits / n);
    printf("Fault Ratio           : %.2f\n", (float)faults / n);
}
