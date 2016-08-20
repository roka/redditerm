CC=gcc
CFLAGS=-Wall
LDFLAGS=-lcurl -ljson-c
DEBUGFLAGS=-DDEBUG_MACRO

debug: local.o parser.o local.o redditerm.o https.o redditerm

https.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c https.c $(LDFLAGS)

local.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c local.c $(LDFLAGS)

parser.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c parser.c $(LDFLAGS)

redditerm.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c redditerm.c $(LDFLAGS)

redditerm:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o redditerm local.o parser.o redditerm.o https.o $(LDFLAGS)

clean:
	rm -f redditerm local *.o

