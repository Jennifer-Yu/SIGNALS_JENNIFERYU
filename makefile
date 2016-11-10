all: signals.o
	gcc -o sigtest signals.o

dir.o: signals.c
	gcc -c signals.c

run: sigtest
	./sigtest

clean:
	rm ./sigtest
	rm ./bubtea.txt
	rm *~