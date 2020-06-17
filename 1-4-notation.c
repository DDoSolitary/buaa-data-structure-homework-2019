#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char s[1000];

int main() {
	int n = 0, p = -1;
	while (true) {
		int c = getchar();
		if (c != '.' && !isdigit(c)) break;
		if (c == '.') p = n;
		else s[n++] = c;
	}
	if (p == -1) p = n;
	int i = 0;
	while (i < n && s[i] == '0') i++;
	putchar(s[i++]);
	if (i < n) {
		putchar('.');
		for (int j = i; j < n; j++) putchar(s[j]);
	}
	putchar('e');
	printf("%d\n", p - i);
}
