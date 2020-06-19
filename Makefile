main: polyapp.o utils.o poly.o 
	gcc -Wall -o main polyapp.o utils.o poly.o

polyapp.o: polyapp.c
	gcc -c -Wall polyapp.c
utils.o: utils.c
	gcc -c -Wall utils.c
poly.o: poly.c
	gcc -c -Wall poly.c
clean:
	rm polyapp.o
	rm utils.o
	rm poly.o
