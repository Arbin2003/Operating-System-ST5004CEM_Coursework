CC=gcc
CFLAGS=-Wall -pthread

all:
	$(CC) $(CFLAGS) server.c -o server
	$(CC) $(CFLAGS) client.c -o client

clean:
	rm -f server client
