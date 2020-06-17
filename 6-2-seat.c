#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct _stu {
	int no;
	char name[21];
	int seat;
} *stu[100];

bool f[101];

int cmp(const void *p1, const void *p2) {
	struct _stu *const *ps1 = p1, *const *ps2 = p2;
	int r = (*ps1)->seat - (*ps2)->seat;
	return r != 0 ? r : (*ps1)->no - (*ps2)->no;
}

int cmp_no(const void *p1, const void *p2) {
	struct _stu *const *ps1 = p1, *const *ps2 = p2;
	return (*ps1)->no - (*ps2)->no;
}

int main() {
	int n;
	scanf("%d", &n);
	FILE *fin = fopen("in.txt", "r");
	int m = 0;
	for (int i = 0; i < n; i++) {
		stu[i] = malloc(sizeof(struct _stu));
		fscanf(fin, "%d%s%d", &stu[i]->no, stu[i]->name, &stu[i]->seat);
		if (stu[i]->seat > m) m = stu[i]->seat;
		f[stu[i]->seat] = true;
	}
	qsort(stu, n, sizeof(struct _stu *), cmp);
	if (n < m) m = n;
	for (int i = 1, j = n; i <= m && i < stu[j - 1]->seat; i++) {
		if (!f[i]) {
			stu[--j]->seat = i;
		}
	}
	qsort(stu, n, sizeof(struct _stu *), cmp);
	m = stu[n - 1]->seat;
	for (int i = 1; i < n; i++) {
		if (stu[i]->seat == stu[i - 1]->seat) {
			stu[i]->seat = ++m;
		}
	}
	qsort(stu, n, sizeof(struct _stu *), cmp_no);
	FILE *fout = fopen("out.txt", "w");
	for (int i = 0; i < n; i++) {
		fprintf(fout, "%d %s %d\n", stu[i]->no, stu[i]->name, stu[i]->seat);
	}
}
