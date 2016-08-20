CC=gcc
CFLAGS=-Wall -lcurl -ljson-c
DEBUGFLAGS=-DDEBUG_MACRO

debug: local.o parser.o local.o redditerm.o redditerm

local.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c local.c

parser.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c parser.c

redditerm.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c redditerm.c

redditerm:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o redditerm local.o parser.o redditerm.o

clean:
	rm -f redditerm local *.o

