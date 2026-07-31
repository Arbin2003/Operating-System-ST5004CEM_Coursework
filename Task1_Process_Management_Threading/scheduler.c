#include <stdio.h>
#include "scheduler.h"

void roundRobin(Process processes[], int n, int quantum)
{
    int completed = 0;
    int time = 0;

    printf("\n========== Round Robin Scheduling ==========\n");
    printf("Time Quantum = %d\n\n", quantum);

    while (completed < n)
    {
        int executed = 0;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0)
            {
                executed = 1;

                printf("Time %2d -> Process P%d running\n",
                       time, processes[i].id);

                if (processes[i].remaining_time > quantum)
                {
                    processes[i].remaining_time -= quantum;
                    time += quantum;
                }
                else
                {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    completed++;

                    printf("Process P%d completed at time %d\n",
                           processes[i].id, time);
                }
            }
        }

        if (!executed)
            break;
    }

    printf("\nAll processes completed successfully.\n");
}
