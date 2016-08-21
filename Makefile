CC=gcc
CFLAGS=-Wall
LDFLAGS=-lcurl -ljson-c -lncurses
DEBUGFLAGS=-DDEBUG_MACRO

debug: local.o parser.o local.o redditerm.o https.o ui.o comments.o redditerm

https.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c https.c $(LDFLAGS)

local.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c local.c $(LDFLAGS)

parser.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c parser.c $(LDFLAGS)

redditerm.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c redditerm.c $(LDFLAGS)

ui.o:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c ui.c $(LDFLAGS)

comments.c:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c comments.c $(LDFLAGS)

redditerm:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o redditerm local.o parser.o redditerm.o https.o ui.o comments.o $(LDFLAGS)

clean:
	rm -f redditerm local *.o

