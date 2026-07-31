CC = gcc
CFLAGS = -Wall

TARGET = task3

OBJS = main.o auth.o file_ops.o logger.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c auth.h file_ops.h
	$(CC) $(CFLAGS) -c main.c

auth.o: auth.c auth.h
	$(CC) $(CFLAGS) -c auth.c

file_ops.o: file_ops.c file_ops.h logger.h
	$(CC) $(CFLAGS) -c file_ops.c

logger.o: logger.c logger.h
	$(CC) $(CFLAGS) -c logger.c

clean:
	rm -f *.o $(TARGET)
