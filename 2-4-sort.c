#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char name[100][23], phone[100][12];
int idx[100], r[100];

int cmp(const void *a, const void *b) {
	int x = *(int *)a, y = *(int *)b;
	int res = strcmp(name[x], name[y]);
	if (res) return res;
	return idx[x] - idx[y];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s", name[i], phone[i]);
		bool f = false;
		for (int j = 0; j < i; j++) {
			if (strcmp(name[i], name[j]) == 0 && strcmp(phone[i], phone[j]) == 0) {
				f = true;
				break;
			}
		}
		if (f) {
			i--;
			n--;
			continue;
		}
		for (int j = i - 1; j >= 0; j--) {
			if (strcmp(name[i], name[j]) == 0) {
				idx[i] = idx[j] + 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) r[i] = i;
	qsort(r, n, sizeof(int), cmp);
	for (int i = 0; i < n; i++) {
		printf("%s", name[r[i]]);
		if (idx[r[i]]) printf("_%d", idx[r[i]]);
		printf(" %s\n", phone[r[i]]);
	}
}
