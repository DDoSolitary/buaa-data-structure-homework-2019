#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct {
	int op, pos;
	void *data;
} st[100000];
char s[513];

void insert(int *len, int pos, char *ops) {
	int oplen = strlen(ops);
	memmove(s + pos + oplen, s + pos, *len - pos);
	s[*len += oplen] = 0;
	memcpy(s + pos, ops, oplen);
}

void delete(int *len, int pos, int oplen) {
	int mlen = *len - pos;
	if (oplen > mlen) {
		oplen = mlen;
	}
	memmove(s + pos, s + pos + oplen, mlen - oplen);
	s[*len -= oplen] = 0;
}

int main() {
	int n, len;
	gets(s);
	len = strlen(s);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		st[i].data = malloc(sizeof(char) * 513);
		scanf("%d%d%s", &st[i].op, &st[i].pos, (char *)st[i].data);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (st[i].op == 1) {
			delete(&len, st[i].pos, strlen(st[i].data));
		} else {
			insert(&len, st[i].pos, st[i].data);
			int oplen = strlen(st[i].data);
			free(st[i].data);
			st[i].data = malloc(sizeof(int));
			*(int *)st[i].data = oplen;
		}
	}
	while (true) {
		int op;
		scanf("%d", &op);
		if (op == -1) {
			break;
		} else if (op == 3) {
			if (n > 0) n--;
		} else {
			st[n].op = op;
			scanf("%d", &st[n].pos);
			if (op == 1) {
				st[n].data = malloc(sizeof(char) * 513);
				scanf("%s", (char *)st[n].data);
			} else {
				st[n].data = malloc(sizeof(int));
				scanf("%d", (int *)st[n].data);
			}
			n++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (st[i].op == 1) {
			insert(&len, st[i].pos, st[i].data);
		} else {
			delete(&len, st[i].pos, *(int *)st[i].data);
		}
	}
	puts(s);
}
