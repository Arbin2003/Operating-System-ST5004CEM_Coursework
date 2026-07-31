#ifndef MEMORY_H
#define MEMORY_H

#define MAX_FRAMES 10
#define MAX_PAGES 100

void fifo(int pages[], int n, int frames);
void lru(int pages[], int n, int frames);

#endif
