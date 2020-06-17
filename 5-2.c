#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct _node {
	struct _node *l, *r;
	char *s;
	int cnt;
} node;

node *new_node(char *s) {
	node *p = malloc(sizeof(node));
	p->l = p->r = NULL;
	p->s = s;
	p->cnt = 1;
	return p;
}

void print_tree(node *p) {
	if (p->l != NULL) {
		print_tree(p->l);
	}
	printf("%s %d\n", p->s, p->cnt);
	if (p->r != NULL) {
		print_tree(p->r);
	}
}

bool next_word(FILE *f, char *s) {
	char c;
	do {
		c = fgetc(f);
	} while (c != EOF && !isalpha(c));
	if (c == EOF) {
		return false;
	}
	do {
		*s++ = tolower(c);
		c = fgetc(f);
	} while (isalpha(c));
	*s = 0;
	return true;
}

int main() {
	FILE *f = fopen("article.txt", "r");
	char *s = malloc(100);
	next_word(f, s);
	node *root = new_node(s);
	while (true) {
		s = malloc(100);
		if (!next_word(f, s)) {
			break;
		}
		node *c = root;
		while (true) {
			int r = strcmp(s, c->s);
			if (r == 0) {
				c->cnt++;
				free(s);
				break;
			} else {
				node **t = r < 0 ? &c->l : &c->r;
				if (*t == NULL) {
					*t = new_node(s);
					break;
				} else {
					c = *t;
				}
			}
		}
	}
	printf("%s", root->s);
	if (root->r != NULL) {
		printf(" %s", root->r->s);
		if (root->r->r != NULL) {
			printf(" %s", root->r->r->s);
		}
	}
	puts("");
	print_tree(root);
}
