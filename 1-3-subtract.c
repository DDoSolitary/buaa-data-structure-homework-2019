#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int a1[1000], a2[1000], a3[1000];
char s[1000];
bool f1, f2, f3;

void read(int *a, bool *f) {
	gets(s);
	if (s[0] == '-') *f = true;
	for (int i = (int)strlen(s) - 1, j = 0; i >= 0 && s[i] != '-'; i--, j++) {
		a[j] = s[i] - '0';
	}
}

void sub(int *b1, int *b2) {
	for (int i = 0; i < 1000; i++) {
		b1[i] -= b2[i];
		if (b1[i] < 0) {
			b1[i] += 10;
			b1[i + 1]--;
		}
	}
}

void add(int *b1, int *b2) {
	for (int i = 0; i < 1000; i++) {
		b1[i] += b2[i];
		if (b1[i] >= 10) {
			b1[i] -= 10;
			b1[i + 1]++;
		}
	}
}

bool cmp() {
	for (int i = 999; i >= 0; i--) {
		if (a1[i] > a2[i]) {
			return true;
		}
		if (a1[i] < a2[i]) {
			return false;
		}
	}
	return true;
}

void print(int *a, bool neg) {
	int i = 999;
	while (i > 0 && a[i] == 0) i--;
	if (neg && (i != 0 || a[0] != 0)) putchar('-');
	for (; i >= 0; i--) putchar(a[i] + '0');
	putchar('\n');
}

int main() {
	read(a1, &f1);
	read(a2, &f2);
	if (!f1 && !f2) {
		if (cmp()) {
			sub(a1, a2);
			print(a1, false);
		} else {
			sub(a2, a1);
			print(a2, true);
		}
	} else if (f1 && f2) {
		if (cmp()) {
			sub(a1, a2);
			print(a1, true);
		} else {
			sub(a2, a1);
			print(a2, false);
		}
	} else if (f1 && !f2) {
		add(a1, a2);
		print(a1, true);
	} else { // !f1 && f2
		add(a1, a2);
		print(a1, false);
	}
}
