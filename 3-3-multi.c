#include <stdio.h>
#include <stdlib.h>

#define N 1000000

typedef struct _item {
	int c;
	int e;
} item;

item p1[N], p2[N], pr[N * 2];

int cmp(const void *p, const void *q) {
	return ((item *)p)->e - ((item *)q)->e;
}

int read_poly(item p[]) {
	int n = 0;
	do {
		scanf("%d %d", &p[n].c, &p[n].e);
		n++;
	} while (getchar() == ' ');
	return n;
}

int main() {
	int n1 = read_poly(p1), n2 = read_poly(p2), m = 0;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			int c = p1[i].c * p2[j].c, e = p1[i].e + p2[j].e;
			int k = 0;
			while (k < m && pr[k].e != e) k++;
			if (k == m) {
				m++;
				pr[k].e = e;
			}
			pr[k].c += c;
		}
	}
	qsort(pr, m, sizeof(item), cmp);
	for (int i = m - 1; i >= 0; i--) {
		printf("%d %d ", pr[i].c, pr[i].e);
	}
	printf("\n");
}
