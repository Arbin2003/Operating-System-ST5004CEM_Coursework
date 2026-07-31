CC = gcc
CFLAGS = -Wall

TARGET = task2

OBJS = main.o fifo.o lru.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c memory.h
	$(CC) $(CFLAGS) -c main.c

fifo.o: fifo.c memory.h
	$(CC) $(CFLAGS) -c fifo.c

lru.o: lru.c memory.h
	$(CC) $(CFLAGS) -c lru.c

clean:
	rm -f *.o $(TARGET)
