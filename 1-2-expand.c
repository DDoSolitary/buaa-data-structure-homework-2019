#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char s1[10000], s2[10000];

int main() {
	gets(s1);
	int n = 0;
	for (int i = 0; s1[i]; i++) {
		char c1 = s1[i];
		if (s1[i + 1] == '-') {
			char c2 = s1[i + 2];
			if (c1 < c2) {
				if (isdigit(c1) && isdigit(c2) || islower(c1) && islower(c2) || isupper(c1) && isupper(c2)) {
					for (; c1 < c2; c1++) {
						s2[n++] = c1;
					}
					i++;
					continue;
				}
			}
		}
		s2[n++] = c1;
	}
	s2[n] = 0;
	puts(s2);
}
