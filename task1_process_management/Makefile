CC = gcc
CFLAGS = -Wall -pthread

TARGET = task1

OBJS = main.o scheduler.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c scheduler.h
	$(CC) $(CFLAGS) -c main.c

scheduler.o: scheduler.c scheduler.h
	$(CC) $(CFLAGS) -c scheduler.c

clean:
	rm -f *.o $(TARGET)
