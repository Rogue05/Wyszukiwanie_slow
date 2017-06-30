CC = gcc

run_and_test: clear main
	./slowa < test

and_run: clear main
	./slowa

allagain: clear main

main: slowa.c text.o text.h
	$(CC) slowa.c text.o -o slowa

text.o: text.c text.h
	$(CC) -c text.c -o text.o

clear:
	rm -f *.o
	rm -f slowa
	rm -f *~

final:
	cd ..
	tar -cvf wyszukiwanie235291.tar Slowa
	uuencode wyszukiwanie235291.tar wyszukiwanie235291.tar > wyszukiwanie235291.tar.uu
	cd Slowa
