a.out: edycja.o main.o sortowanie.o ugrupowanie.o zapis_odczyt.o
	gcc -g edycja.o main.o sortowanie.o ugrupowanie.o zapis_odczyt.o
edycja.o: edycja.c
	gcc -c -g edycja.c -o edycja.o
main.o: main.c
	gcc -c -g main.c -o main.o
sortowanie.o: sortowanie.c
	gcc -c -g sortowanie.c -o sortowanie.o
ugrupowanie.o: ugrupowanie.c
	gcc -c -g ugrupowanie.c -o ugrupowanie.o
zapis_odczyt.o: zapis_odczyt.c
	gcc -c -g zapis_odczyt.c -o zapis_odczyt.o

