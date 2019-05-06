CC=cc
CFLAGS=-ansi
DEFS=linkedList.h

%o: %c $(DEFS)
	$(CC) -c -o linkedList.c main.c $(CFLAGS)

linkedList: linkedList.o main.o
	$(CC) -o linkedList linkedList.o main.o

clean:
	rm *.o linkedList
