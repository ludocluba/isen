all: exo2.o
	gcc exo2.o -o exo2

exo2.o: exo2.c
	gcc -c exo2.c

clean:
	rm exo2.o exo2

package:
	tar cvf exo2.tar exo2.c makefile
	gzip exo2.tar
