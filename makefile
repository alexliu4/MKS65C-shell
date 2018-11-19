all: fork.o
	gcc fork.o

run: all
	./a.out
	make clean
 
file.o: fork.c
	gcc -c fork.c

clean:
	rm *.o
	rm *.out
