CC=gcc
CFLAGS=-Wall -lcurl -ljson-c

all: https.o redditerm

https.o:
	$(CC) $(CFLAGS) -c https.c	

redditerm: https.o
	$(CC) $(CFLAGS) -o redditerm https.o

clean:
	rm redditerm *.o

