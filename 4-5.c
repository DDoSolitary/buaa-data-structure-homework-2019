#include <stdio.h>

int q[100000];

int main() {
	int t, l = 0, r = 0, m = 3;
	scanf("%d", &t);
	for (int i = 0; i < t || l < r; i++) {
		if (i < t) {
			int x;
			scanf("%d", &x);
			r += x;
			while ((r - l) / m >= 7 && m < 5) m++;
		}
		for (int j = 0; j < m && l < r; j++) {
			printf("%d : %d\n", l + 1, q[l]);
			l++;
		}
		while ((r - l) / m < 7 && m > 3) m--;
		for (int j = l; j < r; j++) {
			q[j]++;
		}
	}
}
