all: final

final: list vector

list: list.o box mylist
        gcc list.o -o list -Wall

list.o: list.c
        gcc -c list.c

vector: vector.o box myvector
        gcc vector.o -o vector -Wall

vector.o: vector.c
        gcc -c vector.c

clean:
        rm -rf *.c *.o
