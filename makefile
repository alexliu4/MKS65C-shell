all: shell.o
	gcc shell.o

run: all
	./a.out
	make clean

file.o: shell.c
	gcc -c shell.c

clean:
	rm *.o
	rm *.out
