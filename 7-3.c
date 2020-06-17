#include <stdio.h>
#include <stdlib.h>

struct edge {
	int id, u, v, w;
} e[1000];

int p[1000], r[1000];

int find(int x) {
	return x == p[x] ? x : (p[x] = find(p[x]));
}

int cmp(const void *p, const void *q) {
	const int *a = p, *b = q;
	return *a - *b;
}

int cmpe(const void *p, const void *q) {
	const struct edge *a = p, *b = q;
	return a->w - b->w;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &e[i].id, &e[i].u, &e[i].v, &e[i].w);
	}
	qsort(e, m, sizeof(struct edge), cmpe);
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	int ans = 0, cnt = 0;
	for (int i = 0; i < m; i++) {
		int x = find(e[i].u), y = find(e[i].v);
		if (x != y) {
			p[x] = y;
			ans += e[i].w;
			r[cnt++] = e[i].id;
			if (cnt == n - 1) {
				break;
			}
		}
	}
	printf("%d\n", ans);
	qsort(r, cnt, sizeof(int), cmp);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", r[i]);
	}
	printf("\n");
}
