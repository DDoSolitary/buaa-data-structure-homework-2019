#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char key[10000];
bool f[26];

int main() {
	FILE *in = fopen("encrypt.txt", "r"), *out = fopen("output.txt", "w");
	int c, n = 0;
	while (islower(c = getchar())) {
		int x = c - 'a';
		if (!f[x]) {
			f[x] = true;
			key[n++] = c;
		}
	}
	for (int i = 25; i >= 0; i--) {
		if (!f[i]) {
			key[n++] = 'a' + i;
		}
	}
	while ((c = fgetc(in)) != EOF) {
		if (islower(c)) fputc(key[c - 'a'], out);
		else fputc(c, out);
	}
}
