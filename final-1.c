#include <stdio.h>
#include <stdlib.h>

struct block {
	int st, len;
} blocks[100], merged[100];

int cmp(const void *p, const void *q) {
	const struct block *a = p, *b = q;
	int r = a->st - b->st;
	return r != 0 ? r : a->len - b->len;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &blocks[i].st, &blocks[i].len);
	}
	qsort(blocks, n, sizeof(struct block), cmp);
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (m > 0 && merged[m - 1].st + merged[m - 1].len == blocks[i].st) {
			merged[m - 1].len += blocks[i].len;
		} else {
			merged[m++] = blocks[i];
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%d %d\n", merged[i].st, merged[i].len);
	}
}
