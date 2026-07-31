#include <stdio.h>
#include "memory.h"

void lru(int pages[], int n, int frames)
{
    int frame[MAX_FRAMES];
    int recent[MAX_FRAMES];
    int hits = 0, faults = 0;

    for (int i = 0; i < frames; i++)
    {
        frame[i] = -1;
        recent[i] = -1;
    }

    printf("\n========== LRU Page Replacement ==========\n");

    for (int i = 0; i < n; i++)
    {
        int found = 0;

        /* Check if page already exists */
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                hits++;
                recent[j] = i;
                break;
            }
        }

        /* Page Fault */
        if (!found)
        {
            int replace = 0;

            /* Find empty frame first */
            for (int j = 0; j < frames; j++)
            {
                if (frame[j] == -1)
                {
                    replace = j;
                    goto INSERT;
                }
            }

            /* Find Least Recently Used page */
            for (int j = 1; j < frames; j++)
            {
                if (recent[j] < recent[replace])
                    replace = j;
            }

INSERT:
            frame[replace] = pages[i];
            recent[replace] = i;
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

    printf("\nLRU Statistics\n");
    printf("Hits   : %d\n", hits);
    printf("Faults : %d\n", faults);
    printf("Hit Ratio   : %.2f\n", (float)hits / n);
    printf("Fault Ratio : %.2f\n", (float)faults / n);
}
