#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int st[10000];

int calc_op(int x, int y, char op) {
	if (op == '+') {
		return x + y;
	} else if (op == '-') {
		return x - y;
	} else if (op == '*') {
		return x * y;
	} else if (op == '/') {
		return x / y;
	} else { // op == '%'
		return x % y;
	}
}

int calc_l1(int n) {
	int m = n;
	while (m - 2 >= 0 && (st[m - 2] == '*' || st[m - 2] == '/' || st[m - 2] == '%')) m -= 2;
	for (int i = m; i < n; i += 2) {
		st[m - 1] = calc_op(st[m - 1], st[i + 1], st[i]);
	}
	return m;
}

int calc_l2(int n) {
	int m = n;
	while (m - 2 >= 0 && (st[m - 2] == '+' || st[m - 2] == '-')) m -= 2;
	for (int i = m; i < n; i += 2) {
		st[m - 1] = calc_op(st[m - 1], st[i + 1], st[i]);
	}
	return m;
}

int main() {
	int n = 0;
	char c = getchar();
	while (true) {
		while (c == ' ') {
			c = getchar();
		}
		if (isdigit(c)) {
			st[n] = 0;
			do {
				st[n] = st[n] * 10 + c - '0';
				c = getchar();
			} while (isdigit(c));
			n++;
		} else {
			if (c == '=') {
				break;
			} else if (c == '(' || c == '*' || c == '/' || c == '%') {
				st[n++] = c;
			} else if (c == ')') {
				int m = calc_l2(calc_l1(n));
				st[m - 2] = st[m - 1];
				n = m - 1;
			} else { // c == '+' || c == '-'
				int m = calc_l1(n);
				st[m] = c;
				n = m + 1;
			}
			c = getchar();
		}
	}
	calc_l2(calc_l1(n));
	printf("%d\n", st[0]);
}
