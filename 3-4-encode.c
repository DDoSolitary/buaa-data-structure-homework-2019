#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#pragma GCC diagnostic ignored "-Wchar-subscripts"

char key[33], map[127];
bool f[127];

typedef struct _node {
	char c;
	struct _node *prev, *next;
} node;

node *new_node(char c) {
	node *p = (node *)malloc(sizeof(node));
	p->c = c;
	p->prev = p->next = p;
	return p;
}

void insert_node(node *p1, node *p2) {
	p2->prev = p1;
	p2->next = p1->next;
	p2->prev->next = p2->next->prev = p2;
}

node *remove_node(node *p) {
	p->prev->next = p->next;
	p->next->prev = p->prev;
	node *t = p->next;
	free(p);
	return t;
}

int main() {
	fgets(key, 33, stdin);
	int n = 0;
	for (int i = 0; key[i] >= 32; i++) {
		if (!f[key[i]]) {
			f[key[i]] = true;
			key[n++] = key[i];
		}
	}
	key[n] = 0;
	node *p = new_node(key[0]);
	for (int i = 1; i < n; i++) {
		insert_node(p, new_node(key[i]));
		p = p->next;
	}
	for (int i = 32; i < 127; i++) {
		if (!f[i]) {
			insert_node(p, new_node(i));
			p = p->next;
		}
	}
	p = p->next;
	char c0 = p->c, c;
	while (p->next != p) {
		c = p->c;
		p = remove_node(p);
		for (int i = c - 1; i > 0; i--) {
			p = p->next;
		}
		map[c] = p->c;
	}
	map[p->c] = c0;
	FILE *in = fopen("in.txt", "r"), *out = fopen("in_crpyt.txt", "w");
	while ((c = fgetc(in)) != EOF) {
		if (c >= 32 && c < 127) {
			c = map[c];
		}
		fputc(c, out);
	}
	fclose(in);
	fclose(out);
}
