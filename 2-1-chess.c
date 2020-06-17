#include <stdio.h>

int a[19][19];

int main() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < 19; i++) {
		int c = 0, n = 0;
		for (int j = 0; j < 19; j++) {
			if (a[i][j] == c) {
				if (++n == 4 && c != 0 && (j - 4 >= 0 && a[i][j - 4] == 0 || j + 1 < 19 && a[i][j + 1] == 0)) {
					printf("%d:%d,%d\n", c, i + 1, j - 2);
					return 0;
				}
			} else {
				c = a[i][j];
				n = 1;
			}
		}
	}
	for (int j = 0; j < 19; j++) {
		int c = 0, n = 0;
		for (int i = 0; i < 19; i++) {
			if (a[i][j] == c) {
				if (++n == 4 && c != 0 && (i - 4 >= 0 && a[i - 4][j] == 0 || i + 1 < 19 && a[i + 1][j] == 0)) {
					printf("%d:%d,%d\n", c, i - 2, j + 1);
					return 0;
				}
			} else {
				c = a[i][j];
				n = 1;
			}
		}
	}
	for (int j = 0; j < 19 - 3; j++) {
		int c = 0, n = 0;
		for (int i = 0; i + j < 19; i++) {
			if (a[i][i + j] == c) {
				if (++n == 4 && c != 0 && (i - 4 >= 0 && a[i - 4][i + j - 4] == 0 || i + j + 1 < 19 && a[i + 1][i + j + 1] == 0)) {
					printf("%d:%d,%d\n", c, i - 2, i + j - 2);
					return 0;
				}
			} else {
				c = a[i][i + j];
				n = 1;
			}
		}
	}
	for (int i = 1; i < 19 - 3; i++) {
		int c = 0, n = 0;
		for (int j = 0; i + j < 19; j++) {
			if (a[i + j][j] == c) {
				if (++n == 4 && c != 0 && (j - 4 >= 0 && a[i + j - 4][j - 4] == 0 || i + j + 1 < 19 && a[i + j + 1][j + 1] == 0)) {
					printf("%d:%d,%d\n", c, i + j - 2, j - 2);
					return 0;
				}
			} else {
				c = a[i + j][j];
				n = 1;
			}
		}
	}
	for (int j = 3; j < 19; j++) {
		int c = 0, n = 0;
		for (int i = 0; j - i >= 0; i++) {
			if (a[i][j - i] == c) {
				if (++n == 4 && c != 0 && (i - 4 >= 0 && a[i - 4][j - i + 4] == 0 || j - i - 1 >= 0 && a[i + 1][j - i - 1] == 0)) {
					printf("%d:%d,%d\n", c, i - 2, j - i + 4);
					return 0;
				}
			} else {
				c = a[i][j - i];
				n = 1;
			}
		}
	}
	for (int i = 1; i < 19 - 3; i++) {
		int c = 0, n = 0;
		for (int j = 0; i + j < 19; j++) {
			if (a[i + j][18 - j] == c) {
				if (++n == 4 && c != 0 && (j - 4 >= 0 && a[i + j - 4][18 - j + 4] == 0 || i + j + 1 < 19 && a[i + j + 1][18 - j - 1] == 0)) {
					printf("%d:%d,%d\n", c, i + j - 2, 18 - j + 4);
					return 0;
				}
			} else {
				c = a[i + j][18 - j];
				n = 1;
			}
		}
	}
	puts("No");
}
