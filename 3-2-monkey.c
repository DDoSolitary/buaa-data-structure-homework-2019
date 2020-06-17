#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int id;
	struct _node *prev, *next;
} node;

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	node *p1 = (node *)malloc(sizeof(node)), *p2 = p1;
	p1->id = 1;
	p1->next = p1;
	p1->prev = p1;
	for (int i = 2; i <= n; i++) {
		node *p = (node *)malloc(sizeof(node));
		p->id = i;
		p->prev = p1;
		p->next = p1->next;
		p->prev->next = p;
		p->next->prev = p;
		p1 = p;
		if (i == q) {
			p2 = p;
		}
	}
	while (p2->next != p2) {
		for (int i = 0; i < m - 1; i++) {
			p2 = p2->next;
		}
		node *p = p2;
		p2 = p->next;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
	printf("%d\n", p2->id);
}
