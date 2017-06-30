/*
Wojciech Sopot
235 291
Wyszukiwanie przyblizone

do testow wykorzystalem tekst pierwszej  ksiegi PT
pan_tadeusz/ksiega01.txt

testy (wzorce) :
Tadeusz - sprawdzenie czy program dziala dla bezbledznego wsorca
szala - sprawdzenie czy program wychwytuje dodatkowe i brakujace litery
Tadesuz - Sprawdzenie czy program wykrywa czeskie bledy
Tadesu - sprawdzenie czy program przepusci dwa bledy
Tades - sprawdzenie czy program przepusci miszane bled
Tade - sprawdzenie czy program zablokuje dla trzech bledow
sldkfjhglkasuhndfkcshdfkjahgskjdhfsjcahgfjahfjahsg - sprawdzenie czy program zadziala dla dlogoiego slowa
i - sprawdzenie czy program zadziala dla krotkiego slowa

wszystkie wyrzej wymienione testy program przeszedl,
wynikow nie wkleilem poniewarz sprawozdanie staloby sie nieczytelne

Wnioski:
Program poprawnie dziala
Programowanie dynamiczne okazalo sie wydajnym narzedziem do rozwiazania tego problemu.
*/

#include <stdio.h>
#include "text.h"

int main() {

	int i, tmp, wystapil_wzorzec, nr_linii;
	text tekst;
	FILE *plik;
	
	char nazwa[LETTER_LIMIT]; // nazwa pliku
	char wzorzec[LETTER_LIMIT]; 
	char buf[LINE_LIMIT];

	printf("Podaj zrodlo tekstu:\n");
	scanf("%s", nazwa);
	
	plik = fopen(nazwa, "r");
	if (plik == NULL) printf("Problem z odczytem pliku");

	printf("Podaj wzorzec:\n");
	scanf("%s", wzorzec);
	
	nr_linii = 0; // do wypisywania numewrow linii

	/* odczytanie pliku */
	while (!feof(plik)) {
		fgets(buf, LINE_LIMIT, plik);
		nr_linii++;

		/* sprawdzenie czy w danej linijce wystepuje dopasownie */
		getText(buf, &tekst);
		wystapil_wzorzec = NO;
		for (i = 0; i < tekst.length; i++) {
			tmp = OdlegloscDamerauLevenschteina(tekst.word[i], wzorzec);
			if (tmp <= 2) {
				wystapil_wzorzec = YES;
				break;
			}
		}
		
		/* wypisanie linii gdy wystapi wzorzec */
		if (wystapil_wzorzec) {
			printf("%d\t", nr_linii);
			for (i = 0; i < tekst.length; i++) printf(" %s", tekst.word[i]);
			printf("\t ");

			for (i = 0; i < tekst.length; i++) {
				tmp = OdlegloscDamerauLevenschteina(tekst.word[i], wzorzec);
				if (tmp <= 2) PODKRESL(strlen(tekst.word[i]), '^');
				if (tmp > 2) PODKRESL(strlen(tekst.word[i]), ' ');
				printf(" ");
			}
			printf("\n");
		}
	}

	return 0;
}
