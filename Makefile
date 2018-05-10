all: final

final: list vector

list: list.o 
        gcc list.o -o list -Wall

list.o: list.c
        g++ -c list.c

vector: vector.o 
        gcc vector.o -o vector -Wall

vector.o: vector.c
        g++ -c vector.c

clean:
        rm -rf *.c *.o
