#ifndef MEMORY_H
#define MEMORY_H

#define MAX_FRAMES 3
#define MAX_PAGES 20

void fifo(int pages[], int n, int frames);
void lru(int pages[], int n, int frames);

#endif
