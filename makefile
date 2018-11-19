all: shell.o fork.o strep.o
	gcc shell.o fork.o strep.o -o terminal

run: all
	./terminal
	make clean

shell.o: shell.c
	gcc -c shell.c

fork.o: fork.c
	gcc -c fork.c

strep.o: strep.c
	gcc -c strep.c

clean:
	rm *.o
	rm terminal
