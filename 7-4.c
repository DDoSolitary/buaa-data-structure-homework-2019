#include <stdio.h>
#include <string.h>

struct {
	char s[100];
	int ic;
} v[1000];
char s[100];
int n, g[1000][1000], q[1000], inq[1000], dis[1000], p[1000], r[1000];

int find_id(char *s, int ic) {
	for (int i = 0; i < n; i++) {
		if (strcmp(s, v[i].s) == 0) {
			return i;
		}
	}
	strcpy(v[n].s, s);
	v[n].ic = ic;
	return n++;
}

int main() {
	FILE *f = fopen("bgstations.txt", "r");
	int m;
	fscanf(f, "%d\n", &m);
	for (int i = 0; i < m; i++) {
		int x, ln;
		fscanf(f, "%d%d", &x, &ln);
		int pid = -1;
		for (int j = 0; j < ln; j++) {
			int ic;
			fscanf(f, "%s%d", s, &ic);
			int id = find_id(s, ic);
			if (pid != -1) {
				g[id][pid] = g[pid][id] = x;
			}
			pid = id;
		}
	}
	scanf("%s", s);
	int sid = find_id(s, 0);
	scanf("%s", s);
	int tid = find_id(s, 0);
	int qs = 0, qt = 1;
	q[0] = sid;
	inq[sid] = 1;
	memset(dis, 0x3f, sizeof(int) * n);
	dis[sid] = 0;
	while (qs < qt) {
		int u = q[qs++];
		inq[u] = 0;
		for (int i = 0; i < n; i++) {
			if (g[u][i] && dis[u] + 1 < dis[i]) {
				dis[i] = dis[u] + 1;
				p[i] = u;
				if (!inq[i]) {
					q[qt++] = i;
					inq[i] = 1;
				}
			}
		}
	}
	int u = tid, cnt = 1;
	r[0] = tid;
	while (u != sid) {
		u = p[u];
		r[cnt++] = u;
	}
	int ps = cnt - 1;
	printf("%s", v[sid].s);
	for (int i = cnt - 2; i >= 0; i--) {
		if (i == 0 || g[r[i + 1]][r[i]] != g[r[i]][r[i - 1]]) {
			printf("-%d(%d)-%s", g[r[i + 1]][r[i]], ps - i, v[r[i]].s);
			ps = i;
		}
	}
	printf("\n");
}
