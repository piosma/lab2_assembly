all: program2

program2: program2.o funkcja.o
	gcc -m32 program2.o funkcja.o -o program2 -no-pie

program2.o: program2.s
	as --32 program2.s -o program2.o

funkcja.o: funkcja.c
	gcc -m32 -c funkcja.c -o funkcja.o

clean:
	rm -f *.o program2
