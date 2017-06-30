#include "text.h"

void getText(char *buf, text *a) {
	assert(buf != NULL && a != NULL);

	int i;
	char *tmp_pointer;
	
	i = 0;
	tmp_pointer = strtok(buf, " ");
	while (tmp_pointer != NULL){
		a->word[i++] = tmp_pointer;
		tmp_pointer = strtok(NULL, " ");
	}
	a->length = i;
	return;
}

/*
int isalpha(int c) {
	if (97 <= c && c <= 122) return YES; // male litery
	if (41 <= c && c <= 90) return YES; // doze litery
	return NO;
}
*/

int OdlegloscDamerauLevenschteina(char *s1, char *s2) {
	assert(s1 != NULL&&s2 != NULL);
	int i, j;

	// l1 i l2 dlogosci s1 i s2
	int l1 = (unsigned int)strlen(s1);
	int l2 = (unsigned int)strlen(s2);

	int d[LETTER_LIMIT][LETTER_LIMIT];

	/* tworze 'ramke' */
	for (i = 0; i <= l1; i++) d[i][0] = i;
	for (i = 0; i <= l2; i++) d[0][i] = i;

	/* zeruje tablice */
	for (i = 1; i <= l1; i++)
		for (j = 1; j <= l2; j++)
			d[i][j] = 0;

	/* obliczam dlogosc */
	int cost;
	for (i = 1; i <= l1; i++)
		for (j = 1; j <= l2; j++) {
			if (s1[i - 1] == s2[j - 1])	cost = 0; // jesli jest ok
			else cost = 1;
			d[i][j] = MIN_OF_3(d[i - 1][j] + 1, // usuniecie znaku
				d[i][j - 1] + 1, // znak nadmiarowy
				d[i - 1][j - 1] + cost); // literowka
			if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) d[i][j] = MIN(d[i][j], d[i - 2][j - 2] + cost); // czeski blad
		}

	return d[l1][l2]; // ostatnia komorka zawiera szukana odleglosc
}
