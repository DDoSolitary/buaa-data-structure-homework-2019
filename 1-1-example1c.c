#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char s[1000];
int a[1000], b[1000];

int next_int(char **c) {
	int x = 0;
	do {
		x = x * 10 + **c - '0';
		(*c)++;
	} while (isdigit(**c));
	return x;
}

int main() {
	int n = 0;
	while (true) {
		s[n] = (char)getchar();
		if (s[n] == '=') break;
		if (s[n] != ' ') n++;
	}
	char *p = s;
	int m = 0, v1 = next_int(&p), v2 = 0;
	char op = 0;
	if (*p == '*' || *p == '/') {
		m = 1;
		v2 = v1;
		v1 = 0;
		op = '+';
	}
	while (true) {
		if (*p == '=') break;
		char c = *p++;
		int x = next_int(&p);
		if (m == 0) {
			if (*p == '*' || *p == '/') {
				m = 1;
				op = c;
				v2 = x;
			} else if (c == '+') {
				v1 += x;
			} else {
				v1 -= x;
			}
		} else {
			if (c == '*') {
				v2 *= x;
			} else {
				v2 /= x;
			}
			if (*p != '*' && *p != '/') {
				m = 0;
				if (op == '+') {
					v1 += v2;
				} else {
					v1 -= v2;
				}
			}
		}
	}
	printf("%d\n", v1);
	return 0;
}
