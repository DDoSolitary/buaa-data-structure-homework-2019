#include <stdio.h>
#include <string.h>

int g[100][100], n, f[100], q[100];

void dfs(int x, int d) {
	printf("%d ", x);
	f[x] = 1;
	for (int i = 0; i < n; i++) {
		if (g[x][i] && i != d && !f[i]) {
			dfs(i, d);
		}
	}
}

void bfs(int d) {
	memset(f, 0x00, sizeof(int) * n);
	int s = 0, t = 1;
	q[0] = 0;
	f[0] = 1;
	while (s < t) {
		int x = q[s++];
		printf("%d ", x);
		for (int i = 0; i < n; i++) {
			if (g[x][i] && i != d && !f[i]) {
				f[i] = 1;
				q[t++] = i;
			}
		}
	}
	printf("\n");
}

int main() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x][y] = g[y][x] = 1;
	}
	memset(f, 0x00, sizeof(int) * n);
	dfs(0, 0);
	printf("\n");
	bfs(0);
	int d;
	scanf("%d", &d);
	memset(f, 0x00, sizeof(int) * n);
	dfs(0, d);
	printf("\n");
	bfs(d);
}
