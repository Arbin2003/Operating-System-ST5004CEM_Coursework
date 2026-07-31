#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "scheduler.h"

#define NUM_THREADS 3
#define ITERATIONS 100000

/* Shared variables */
int sharedCounter = 0;
int raceCounter = 0;

pthread_mutex_t counterMutex;
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

/* ---------------- Synchronization Example ---------------- */

void *worker(void *arg)
{
    int id = *(int *)arg;

    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&counterMutex);

        sharedCounter++;
        printf("Thread %d updated counter to %d\n", id, sharedCounter);

        pthread_mutex_unlock(&counterMutex);

        usleep(100000);
    }

    return NULL;
}

/* ---------------- Race Condition ---------------- */

void *raceWorker(void *arg)
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        raceCounter++;     // No mutex (intentional)
    }

    return NULL;
}

/* ---------------- Mutex Protected ---------------- */

void *safeWorker(void *arg)
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        pthread_mutex_lock(&counterMutex);
        raceCounter++;
        pthread_mutex_unlock(&counterMutex);
    }

    return NULL;
}

/* ---------------- Deadlock Prevention ---------------- */

void *taskA(void *arg)
{
    pthread_mutex_lock(&lock1);
    printf("Task A acquired Lock 1\n");

    sleep(1);

    pthread_mutex_lock(&lock2);
    printf("Task A acquired Lock 2\n");

    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);

    return NULL;
}

void *taskB(void *arg)
{
    /* Same lock order prevents deadlock */
    pthread_mutex_lock(&lock1);
    printf("Task B acquired Lock 1\n");

    sleep(1);

    pthread_mutex_lock(&lock2);
    printf("Task B acquired Lock 2\n");

    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);

    return NULL;
}

/* ---------------- Main ---------------- */

int main()
{
    printf("=============================================\n");
    printf("Task 1 - Process Management and Threading\n");
    printf("=============================================\n");

    pthread_mutex_init(&counterMutex, NULL);

    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS] = {1, 2, 3};

    printf("\n--- Thread Synchronization ---\n");

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, worker, &ids[i]);

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    printf("\nFinal Shared Counter = %d\n", sharedCounter);

    /* ---------------- Race Condition ---------------- */

    printf("\n--- Race Condition (Without Mutex) ---\n");

    raceCounter = 0;

    pthread_t r1, r2;

    pthread_create(&r1, NULL, raceWorker, NULL);
    pthread_create(&r2, NULL, raceWorker, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);

    printf("Expected Counter : %d\n", ITERATIONS * 2);
    printf("Actual Counter   : %d\n", raceCounter);

    /* ---------------- Mutex Example ---------------- */

    printf("\n--- Synchronization (With Mutex) ---\n");

    raceCounter = 0;

    pthread_create(&r1, NULL, safeWorker, NULL);
    pthread_create(&r2, NULL, safeWorker, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);

    printf("Expected Counter : %d\n", ITERATIONS * 2);
    printf("Actual Counter   : %d\n", raceCounter);

    /* ---------------- Round Robin ---------------- */

    Process processes[] =
    {
        {1, 8, 8},
        {2, 4, 4},
        {3, 9, 9},
        {4, 5, 5}
    };

    roundRobin(processes, 4, 2);

    /* ---------------- Deadlock Prevention ---------------- */

    printf("\n--- Deadlock Prevention ---\n");

    pthread_t d1, d2;

    pthread_create(&d1, NULL, taskA, NULL);
    pthread_create(&d2, NULL, taskB, NULL);

    pthread_join(d1, NULL);
    pthread_join(d2, NULL);

    pthread_mutex_destroy(&counterMutex);

    printf("\nProgram completed successfully.\n");

    return 0;
}
