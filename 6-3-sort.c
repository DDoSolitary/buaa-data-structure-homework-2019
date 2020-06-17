#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int a[100], cnt, h[100], t[100];

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void heap_adjust(int i, int n) {
	for (int j = i * 2 + 1; j < n; i = j, j = i * 2 + 1) {
		if (j + 1 < n && h[j + 1] > h[j]) {
			j++;
		}
		cnt++;
		if (h[j] > h[i]) {
			swap(h + i, h + j);
		} else {
			break;
		}
	}
}

void merge_sort(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int i = l, j = mid + 1, n = 0;
	while (i <= mid && j <= r) {
		cnt++;
		if (a[i] <= a[j]) {
			t[n++] = a[i++];
		} else {
			t[n++] = a[j++];
		}
	}
	while (i <= mid) {
		t[n++] = a[i++];
	}
	while (j <= r) {
		t[n++] = a[j++];
	}
	memcpy(a + l, t, sizeof(int) * n);
}

void quick_sort(int l, int r) {
	if (l >= r) return;
	int j = l + 1;
	for (int i = l + 1; i <= r; i++) {
		cnt++;
		if (a[i] < a[l]) {
			swap(a + i, a + (j++));
		}
	}
	swap(a + l, a + j - 1);
	quick_sort(l, j - 2);
	quick_sort(j, r);
}

int main() {
	int n, op;
	scanf("%d%d", &n, &op);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	if (op == 1) {
		for (int i = 0; i <= n - 2; i++) {
			int k = n - 1;
			for (int j = n - 2; j >= i; j--) {
				if (a[j] < a[k]) k = j;
				cnt++;
			}
			swap(a + i, a + k);
		}
	} else if (op == 2) {
		for (int i = 0; i <= n - 2; i++) {
			bool f = false;
			for (int j = 0; j < n - i - 1; j++) {
				if (a[j] > a[j + 1]) {
					swap(a + j, a + j + 1);
					f = true;
				}
				cnt++;
			}
			if (!f) break;
		}
	} else if (op == 3) {
		memcpy(h, a, sizeof(int) * n);
		for (int i = n - 1; i >= 0; i--) {
			heap_adjust(i, n);
		}
		for (int i = n - 1; i >= 0; i--) {
			a[i] = h[0];
			h[0] = h[i];
			heap_adjust(0, i);
		}
	} else if (op == 4) {
		merge_sort(0, n - 1);
	} else { // op == 5
		quick_sort(0, n - 1);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n%d\n", cnt);
}
