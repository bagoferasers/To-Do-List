PROGRAMS = main
CC = gcc
CFLAGS = -Wall -g
all: $(PROGRAMS)
clean:
	rm -f *.o
# C compilations
heapsort.o: heapsort.c heapsort.h taskNode.h
	$(CC) $(CFLAGS) -c heapsort.c 
main.o: main.c heapsort.h taskNode.h
	$(CC) $(CFLAGS) -c main.c
taskNode.o: taskNode.c taskNode.h 
	$(CC) $(CFLAGS) -c taskNode.c 
# Executable programs
main: main.o heapsort.o taskNode.o
	$(CC) $(CFLAGS) -o main main.o heapsort.o taskNode.o