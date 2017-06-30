#ifndef text_h_
#define text_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define YES 1
#define NO 0
#define LETTER_LIMIT 100
#define WORD_LIMIT 10000
#define LINE_LIMIT 1000000

/* moje makra */
#define MIN(x, y) (((x)<(y))?(x):(y))
#define MIN_OF_3(x, y, z) MIN(MIN((x), (y)), (z))
#define PODKRESL(times, my_char) do{int tmp = (times); for(tmp; tmp>0; tmp--) printf("%c", my_char);}while(0); // podkreslatimes razy znakiem my_char

typedef struct text {
	char *word[WORD_LIMIT]; // tablica slow danej linii 
	int length; // dlogosc tablicy wyrazow
}text;

//int isalpha(int c);
void getText(char *buf, text *a);

int OdlegloscDamerauLevenschteina(char *s1, char *s2); // s1, s2 s³owa porownywane

#endif