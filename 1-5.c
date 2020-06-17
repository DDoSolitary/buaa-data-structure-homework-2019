#include <stdio.h>
#include <stdbool.h>

void swap(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
}

void reverse(int *l, int *r) {
	while (l < r) {
		swap(l, r);
		l++;
		r--;
	}
}

bool next_perm(int *a, int n) {
	int i = n - 1;
	while (i > 0 && a[i] < a[i - 1]) i--;
	if (i == 0) return false;
	int j = n - 1;
	while (j >= i && a[j] < a[i - 1]) j--;
	swap(a + j, a + i - 1);
	reverse(a + i, a + n - 1);
	return true;
}

int main() {
	int n, a[10];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) a[i] = i + 1;
	do {
		for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
		printf("%d\n", a[n - 1]);
	} while (next_perm(a, n));
}
