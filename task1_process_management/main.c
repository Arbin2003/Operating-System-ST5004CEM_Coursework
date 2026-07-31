#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "scheduler.h"

#define NUM_THREADS 3

int sharedCounter = 0;
pthread_mutex_t mutex;

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

/* ---------------- Thread Synchronization ---------------- */

void *worker(void *arg)
{
    int id = *(int *)arg;

    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutex);

        sharedCounter++;
        printf("Thread %d -> Counter = %d\n", id, sharedCounter);

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    pthread_exit(NULL);
}

/* ---------------- Race Condition ---------------- */

void raceConditionDemo()
{
    printf("\n=====================================\n");
    printf("Race Condition Demonstration\n");
    printf("=====================================\n");

    int counter = 0;

    for (int i = 0; i < 100000; i++)
        counter++;

    printf("Counter without synchronization example: %d\n", counter);
    printf("Mutex is used in worker threads to avoid race conditions.\n");
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

    pthread_exit(NULL);
}

void *taskB(void *arg)
{
    pthread_mutex_lock(&lock1);
    printf("Task B acquired Lock 1\n");

    sleep(1);

    pthread_mutex_lock(&lock2);
    printf("Task B acquired Lock 2\n");

    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);

    pthread_exit(NULL);
}

/* ---------------- Main ---------------- */

int main()
{
    printf("=====================================\n");
    printf("Task 1 - Process Management\n");
    printf("=====================================\n");

    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS] = {1, 2, 3};

    pthread_mutex_init(&mutex, NULL);

    printf("\nCreating Threads...\n\n");

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, worker, &ids[i]);

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    printf("\nFinal Counter Value = %d\n", sharedCounter);

    raceConditionDemo();

    Process processes[] = {
        {1, 8, 8},
        {2, 4, 4},
        {3, 9, 9},
        {4, 5, 5}
    };

    roundRobin(processes, 4, 2);

    printf("\n=====================================\n");
    printf("Deadlock Prevention Demo\n");
    printf("=====================================\n");

    pthread_t t1, t2;

    pthread_create(&t1, NULL, taskA, NULL);
    pthread_create(&t2, NULL, taskB, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);

    printf("\nProgram Finished Successfully.\n");

    return 0;
}
