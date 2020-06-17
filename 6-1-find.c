#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	int id;
	struct _node *next;
} node;

char dic[4000][21];
int index[27];
node *ht[4000];

unsigned hash(char *s) {
	unsigned h = 0;
	for (char *p = s; *p != 0; p++) {
		h = h * 37 + *p;
	}
	return h % 3001;
}

int main() {
	FILE *fdic = fopen("dictionary3000.txt", "r");
	char c = 0;
	int n;
	for (n = 0; fscanf(fdic, "%s", dic[n]) != EOF; n++) {
		if (dic[n][0] != c) {
			c = dic[n][0];
			index[c - 'a'] = n;
		}
		node **x = &ht[hash(dic[n])];
		while (*x != NULL) x = &(*x)->next;
		*x = malloc(sizeof(node));
		(*x)->id = n;
		(*x)->next = NULL;
	}
	index[26] = n;
	index['x' - 'a'] = index['y' - 'a'];
	int op;
	char s[21];
	while (scanf("%s%d", s, &op) != EOF) {
		bool found = false;
		int cnt = 0;
		if (op == 1) {
			for (; cnt < n; cnt++) {
				int r = strcmp(s, dic[cnt]);
				found = r == 0;
				if (r <= 0) {
					cnt++;
					break;
				}
			}
		} else if (op == 2 || op == 3) {
			int l, r;
			if (op == 2) {
				l = 0;
				r = n - 1;
			} else { // op == 3
				int x = s[0] - 'a';
				l = index[x];
				r = index[x + 1] - 1;
			}
			while (l <= r) {
				int mid = (l + r) / 2;
				int rt = strcmp(s, dic[mid]);
				cnt++;
				if (rt == 0) {
					found = true;
					break;
				} else if (rt < 0) {
					r = mid - 1;
				} else { // rt > 0
					l = mid + 1;
				}
			}
		} else { // op == 4
			for (node *x = ht[hash(s)]; x != NULL; x = x->next) {
				int r = strcmp(s, dic[x->id]);
				cnt++;
				found = r == 0;
				if (r <= 0) break;
			}
		}
		printf("%d %d\n", found, cnt);
	}
}
