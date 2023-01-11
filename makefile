PROGRAMS = main
CC = gcc
CFLAGS = -Wall -g
all: $(PROGRAMS)
clean:
	rm -f *.o
# C compilations
heapsort.o: heapsort.c heapsort.h taskNode.h
	$(CC) $(CFLAGS) -c heapsort.c 
driver.o: main.c heapsort.h taskNode.h
	$(CC) $(CFLAGS) -c main.c
# Executable programs
main: main.o heapsort.o
	$(CC) $(CFLAGS) -o main main.o heapsort.o