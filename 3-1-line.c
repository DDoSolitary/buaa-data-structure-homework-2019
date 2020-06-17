#include <stdio.h>
#include <stdlib.h>

struct seg {
	int x1;
	int y1;
	int x2;
	int y2;
} segs[100];

int cmp(const void *p, const void *q) {
	struct seg *a = (struct seg *)p, *b = (struct seg *)q;
	return a->x1 != b->x1 ? a->x1 - b->x1 : a->y1 - b->y1;
}

int f[100], g[100][2];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &segs[i].x1, &segs[i].y1, &segs[i].x2, &segs[i].y2);
	}
	qsort(segs, n, sizeof(struct seg), cmp);
	for (int i = 0; i < n; i++) {
		f[i] = 1;
		g[i][0] = segs[i].x1;
		g[i][1] = segs[i].y1;
		for (int j = 0; j < i; j++) {
			if (segs[i].x1 == segs[j].x2 && segs[i].y1 == segs[j].y2) {
				if (f[j] + 1 > f[i]) {
					f[i] = f[j] + 1;
					g[i][0] = g[j][0];
					g[i][1] = g[j][1];
				}
			}
		}
	}
	int rf = 0, rg[2] = {0};
	for (int i = 0; i < n; i++) {
		if (f[i] > rf) {
			rf = f[i];
			rg[0] = g[i][0];
			rg[1] = g[i][1];
		}
	}
	printf("%d %d %d\n", rf, rg[0], rg[1]);
}
