all: main.o dirScan.o
	gcc -o homework main.o dirScan.o
main.o: main.c dirScan.h
	gcc -c main.c
dirScan.o: dirScan.c dirScan.h
	gcc -c dirScan.c

clean:
	rm *.o
	rm homework
run: all
	./homework
