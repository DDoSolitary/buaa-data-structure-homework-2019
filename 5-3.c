#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _node {
	int x;
	struct _node *l, *r;
} node;

node *st[10000];

node *new_node(int x) {
	node *p = malloc(sizeof(node));
	p->l = p->r = NULL;
	p->x = x;
	return p;
}

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

int build_l1(int n) {
	int m = n;
	while (m - 2 >= 0 && (st[m - 2]->x == '*' || st[m - 2]->x == '/' || st[m - 2]->x == '%')) m -= 2;
	for (int i = m; i < n; i += 2) {
		st[i]->l = st[m - 1];
		st[i]->r = st[i + 1];
		st[m - 1] = st[i];
	}
	return m;
}

int build_l2(int n) {
	int m = n;
	while (m - 2 >= 0 && (st[m - 2]->x == '+' || st[m - 2]->x == '-')) m -= 2;
	for (int i = m; i < n; i += 2) {
		st[i]->l = st[m - 1];
		st[i]->r = st[i + 1];
		st[m - 1] = st[i];
	}
	return m;
}

int calc_expr_tree(node *p) {
	if (p->l == NULL) {
		return p->x;
	} else {
		return calc_op(calc_expr_tree(p->l), calc_expr_tree(p->r), p->x);
	}
}

void print_node(node *p) {
	if (p->l == NULL) {
		printf("%d", p->x);
	} else {
		printf("%c", p->x);
	}
}

int main() {
	int n = 0;
	char c = getchar();
	while (true) {
		while (c == ' ') {
			c = getchar();
		}
		if (isdigit(c)) {
			int x = 0;
			do {
				x = x * 10 + c - '0';
				c = getchar();
			} while (isdigit(c));
			st[n++] = new_node(x);
		} else {
			if (c == '=') {
				break;
			} else if (c == '(' || c == '*' || c == '/' || c == '%') {
				st[n++] = new_node(c);
			} else if (c == ')') {
				int m = build_l2(build_l1(n));
				free(st[m - 2]);
				st[m - 2] = st[m - 1];
				n = m - 1;
			} else { // c == '+' || c == '-'
				int m = build_l1(n);
				st[m] = new_node(c);
				n = m + 1;
			}
			c = getchar();
		}
	}
	build_l2(build_l1(n));
	print_node(st[0]);
	if (st[0]->l != NULL) {
		putchar(' ');
		print_node(st[0]->l);
		putchar(' ');
		print_node(st[0]->r);
	}
	putchar('\n');
	printf("%d\n", calc_expr_tree(st[0]));
}
