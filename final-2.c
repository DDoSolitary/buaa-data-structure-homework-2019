#include <stdio.h>
#include <string.h>

struct {
	char name[21];
	int dis;
} dest[50];

struct cabin {
	char id[5];
	int dis;
} cabins[51];

char buf[21];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d", dest[i].name, &dest[i].dis);
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s%s", buf, cabins[i].id);
		for (int j = 0; j < m; j++) {
			if (strcmp(buf, dest[j].name) == 0) {
				cabins[i].dis = dest[j].dis;
			}
		}
	}
	int x = m;
	for (int i = 0; i < m - 1; i++) {
		int k = i;
		for (int j = i + 1; j < m; j++) {
			if (cabins[j].dis > cabins[k].dis) {
				k = j;
			}
		}
		struct cabin t = cabins[k];
		for (int j = k - 1; j >= i; j--) {
			x++;
			cabins[j + 1] = cabins[j];
		}
		cabins[i] = t;
	}
	for (int i = 0; i < m; i++) {
		printf("%s ", cabins[i].id);
	}
	printf("\n%d\n", x);
}
