#include <stdio.h>
#include <stdbool.h>

struct {
	char c;
	int line;
} s[201];
int n, m;
char o[401];

void print_mismatch(char c, int line) {
	printf("without maching '%c' at line %d\n", c, line);
}

int main() {
	freopen("example.c", "r", stdin);
	bool cmt = false;
	int line = 1;
	while (true) {
		char c = getchar();
		if (c == EOF) {
			break;
		} else if (cmt) {
			cmt = false;
			if (c == '/') {
				do {
					c = getchar();
				} while (c != '\n' && c != EOF);
				line++;
			} else if (c == '*') {
				while (true) {
					c = getchar();
					if (c == '\n') {
						line++;
					} else if (c == '*') {
						cmt = true;
					} else if (cmt) {
						cmt = false;
						if (c == '/') break;
					}
				}
			}
		} else if (c == '\n') {
			line++;
		} else if (c == '\'') {
			do {
				c = getchar();
			} while (c != '\'');
		} else if (c == '"') {
			do {
				c = getchar();
			} while (c != '"');
		} else if (c == '/') {
			cmt = true;
		} else if (c == '(') {
			s[n].c = c;
			s[n].line = line;
			n++;
			o[m++] = c;
		} else if (c == '{') {
			if (n > 0 && s[n - 1].c == '(') {
				print_mismatch(s[n - 1].c, s[n - 1].line);
				return 0;
			}
			s[n].c = c;
			s[n].line = line;
			n++;
			o[m++] = c;
		} else if (c == ')') {
			if (n == 0 || s[n - 1].c != '(') {
				print_mismatch(c, line);
				return 0;
			}
			n--;
			o[m++] = c;
		} else if (c == '}') {
			if (n == 0 || s[n - 1].c != '{') {
				print_mismatch(c, line);
				return 0;
			}
			n--;
			o[m++] = c;
		}
	}
	if (n > 0) {
		print_mismatch(s[n - 1].c, s[n - 1].line);
	} else {
		puts(o);
	}
}
