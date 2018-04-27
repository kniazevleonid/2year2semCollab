all: final

final: list vector

list: list.o box mylist
        gcc list.o mylist.h box.h -o list -Wall

list.o: list.c
        gcc -c list.c

mylist: mylist.h
        gcc -c mylist.h

box: box.h
        gcc -c box.h

vector: vector.o box myvector
        gcc vector.o myvector.h box.h -o vector -Wall

vector.o: vector.c
        gcc -c vector.c

myvector: myvector.h
        gcc -c myvector.h

clean:
        rm -rf *.c *.h *.o
