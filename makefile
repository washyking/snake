CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lncurses

OBJECTS = main.o linked.o grid.o buffer.o

all: myprogram

myprogram: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o myprogram $(LIBS)

main.o: main.c linked.h grid.h buffer.h
	$(CC) $(CFLAGS) -c main.c -o main.o

linked.o: linked.c linked.h
	$(CC) $(CFLAGS) -c linked.c -o linked.o

grid.o: grid.c grid.h linked.h
	$(CC) $(CFLAGS) -c grid.c -o grid.o

buffer.o: buffer.c buffer.h 
	$(CC) $(CFLAGS) -c buffer.c -o buffer.o

clean:
	rm -f *.o myprogram
