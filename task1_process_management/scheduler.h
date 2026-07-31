#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX_PROCESSES 5

typedef struct
{
    int id;
    int burst_time;
    int remaining_time;
} Process;

void roundRobin(Process processes[], int n, int quantum);

#endif
