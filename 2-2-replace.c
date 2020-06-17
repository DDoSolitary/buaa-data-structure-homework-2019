#include <stdio.h>
#include <string.h>
#include <ctype.h>

char a[100], b[100], buf[10000];

char *stristr(char *a, char *b) {
	for (int i = 0; a[i]; i++) {
		int j = 0;
		while (b[j] && tolower(a[i + j]) == tolower(b[j])) j++;
		if (!b[j]) return a + i;
	}
	return NULL;
}

int main() {
	FILE *in = fopen("filein.txt", "r"), *out = fopen("fileout.txt", "w");
	gets(a);
	gets(b);
	int alen = strlen(a), flen = fread(buf, 1, 10000, in);
	buf[flen] = 0;
	char *p1 = buf, *p2;
	while ((p2 = stristr(p1, a))) {
		fwrite(p1, 1, p2 - p1, out);
		fprintf(out, "%s", b);
		p1 = p2 + alen;
	}
	fwrite(p1, 1, buf + flen - p1, out);
}
