#include <stdio.h>

struct edge {
	int id, x, y;
} e[1000];

int p[1000], n, m, fv[1000], fe[1000];

int cmp(const void *p, const void *q) {
	const struct edge *a = p, *b = q;
	return a->id - b->id;
}

void dfs(int x, int d) {
	if (x == n - 1) {
		for (int i = 0; i < d; i++) {
			printf("%d ", p[i]);
		}
		printf("\n");
		return;
	}
	fv[x] = 1;
	for (int i = 0; i < m; i++) {
		int y;
		if (e[i].x == x) {
			y = e[i].y;
		} else if (e[i].y==x) {
			y = e[i].x;
		} else {
			continue;
		}
		int id = e[i].id;
		if (!fe[id] && !fv[y]) {
			p[d] = id;
			fe[id] = 1;
			dfs(y, d + 1);
			fe[id] = 0;
		}
	}
	fv[x] = 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &e[i].id, &e[i].x, &e[i].y);
	}
	dfs(0, 0);
}
