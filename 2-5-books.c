#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char name[10000][51], author[10000][21], press[10000][31], date[10000][11], kw[51];
int r[10000];

int cmp(const void *a, const void *b) {
	int x = *(int *)a, y = *(int *)b;
	return strcmp(name[x], name[y]);
}

void print(int i, FILE *f) {
	fprintf(f, "%-50s%-20s%-30s%-10s\n", name[i], author[i], press[i], date[i]);
}

void print_all(int n, FILE *f) {
	for (int i = 0; i < n; i++) {
		print(r[i], f);
	}
}

int main() {
	FILE *in = fopen("books.txt", "r");
	int n = 0;
	while (fscanf(in, "%s %s %s %s", name[n], author[n], press[n], date[n]) != EOF) {
		r[n] = n;
		n++;
	}
	int m = n;
	qsort(r, n, sizeof(int), cmp);
	while (true) {
		int op;
		scanf("%d", &op);
		if (op == 0) break;
		if (op == 1) {
			scanf("%s %s %s %s", name[m], author[m], press[m], date[m]);
			int i = 0;
			while (i < n && strcmp(name[r[i]], name[m]) < 0) i++;
			for (int j = n; j > i; j--) r[j] = r[j - 1];
			r[i] = m;
			n++;
			m++;
		} else if (op == 2) {
			scanf("%s", kw);
			for (int i = 0; i < n; i++) {
				if (strstr(name[r[i]], kw)) {
					print(r[i], stdout);
				}
			}
		} else {
			scanf("%s", kw);
			int i = 0, j = 0;
			while (true) {
				while (j < n && strstr(name[r[j]], kw)) j++;
				if (j == n) break;
				r[i++] = r[j++];
			}
			n = i;
		}
	}
	FILE *out = fopen("ordered.txt", "w");
	print_all(n, out);
}
