#include <stdio.h>
#include <stdbool.h>

int s[100], n;

int main() {
	int op;
	while (true) {
		scanf("%d", &op);
		if (op == 1) {
			int x;
			scanf("%d", &x);
			if (n == 100) {
				printf("error ");
			} else {
				s[n++] = x;
			}
		} else if (op == 0) {
			if (n == 0) {
				printf("error ");
			} else {
				printf("%d ", s[--n]);
			}
		} else break;
	}
	printf("\n");
}
