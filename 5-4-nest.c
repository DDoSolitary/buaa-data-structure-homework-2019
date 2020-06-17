#include <stdio.h>

struct {
	int c1, c2, c3;
} nodes[10000];

int _max(int a, int b) {
	return a > b ? a : b;
}

int get_node_degree(int x) {
	int deg = 0;
	if (nodes[x].c1) deg++;
	if (nodes[x].c2) deg++;
	if (nodes[x].c3) deg++;
	return deg;
}

int get_degree(int x) {
	if (x == 0) return 0;
	return _max(get_node_degree(x), _max(get_degree(nodes[x].c1), _max(get_degree(nodes[x].c2), get_degree(nodes[x].c3))));
}

int get_max_depth(int x, int dep, int tdeg) {
	if (x == 0) return 0;
	return _max(get_node_degree(x) == tdeg ? dep : 0, _max(get_max_depth(nodes[x].c1, dep + 1, tdeg), _max(get_max_depth(nodes[x].c2, dep + 1, tdeg), get_max_depth(nodes[x].c3, dep + 1, tdeg))));
}

int print_nests(int x, int dep, int no, int tdep, int tdeg) {
	if (x == 0) return 0;
	if (dep == tdep && get_node_degree(x) == tdeg) {
		printf("%d %d\n", x, no);
	}
	int cnt = 0;
	cnt += print_nests(nodes[x].c1, dep + 1, no + cnt + 1, tdep, tdeg);
	cnt += print_nests(nodes[x].c2, dep + 1, no + cnt + 1, tdep, tdeg);
	cnt += print_nests(nodes[x].c3, dep + 1, no + cnt + 1, tdep, tdeg);
	return cnt + 1;
}

int main() {
	int n;
	scanf("%d\n", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		scanf("%d%d%d", &nodes[x].c1, &nodes[x].c2, &nodes[x].c3);
	}
	int tdeg = get_degree(1);
	int tdep = get_max_depth(1, 1, tdeg);
	print_nests(1, 1, 1, tdep, tdeg);
}
