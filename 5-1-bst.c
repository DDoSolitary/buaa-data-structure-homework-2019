#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _node {
	struct _node *l, *r;
	int v;
} node;

node *new_node(int v) {
	node *p = malloc(sizeof(node));
	p->l = p->r = NULL;
	p->v = v;
	return p;
}

void print_leaves(node *p, int d) {
	if (p->l == NULL && p->r == NULL) {
		printf("%d %d\n", p->v, d);
		return;
	}
	if (p->l != NULL) {
		print_leaves(p->l, d + 1);
	}
	if (p->r != NULL) {
		print_leaves(p->r, d + 1);
	}
}

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	node *root = new_node(x);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &x);
		node *p = new_node(x), *c = root;
		while (true) {
			node **t = x < c->v ? &c->l : &c->r;
			if (*t == NULL) {
				*t = p;
				break;
			} else {
				c = *t;
			}
		}
	}
	print_leaves(root, 1);
}
