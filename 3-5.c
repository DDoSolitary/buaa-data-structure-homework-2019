#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

char words[10000][100], buf[100];
int count[10000], r[10000];

int cmp(const void *p, const void *q) {
	return strcmp(words[*(int *)p], words[*(int *)q]);
}

int main() {
	FILE *in = fopen("article.txt", "r");
	int n = 0;
	while (true) {
		int c;
		do {
			c = fgetc(in);
		} while (c != EOF && !isalpha(c));
		if (c == EOF) break;
		int m = 0;
		while (c != EOF && isalpha(c)) {
			buf[m++] = tolower(c);
			c = fgetc(in);
		}
		buf[m] = 0;
		int i = 0;
		while (i < n && strcmp(words[i], buf) != 0) {
			i++;
		}
		if (i == n) {
			strcpy(words[n++], buf);
		}
		count[i]++;
		if (c == EOF) break;
	}
	fclose(in);
	for (int i = 0; i < n; i++) {
		r[i] = i;
	}
	qsort(r, n, sizeof(int), cmp);
	for (int i = 0; i < n; i++) {
		printf("%s %d\n", words[r[i]], count[r[i]]);
	}
}
