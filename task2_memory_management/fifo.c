#include <stdio.h>
#include "memory.h"

void fifo(int pages[], int n, int frames)
{
    int frame[MAX_FRAMES];
    int front = 0;
    int hits = 0, faults = 0;

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\n========== FIFO Page Replacement ==========\n");

    for (int i = 0; i < n; i++)
    {
        int found = 0;

        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                hits++;
                break;
            }
        }

        if (!found)
        {
            frame[front] = pages[i];
            front = (front + 1) % frames;
            faults++;
        }

        printf("Page %2d -> ", pages[i]);

        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        if (found)
            printf("(Hit)\n");
        else
            printf("(Fault)\n");
    }

    printf("\nFIFO Statistics\n");
    printf("Hits   : %d\n", hits);
    printf("Faults : %d\n", faults);
    printf("Hit Ratio   : %.2f\n", (float)hits / n);
    printf("Fault Ratio : %.2f\n", (float)faults / n);
}
