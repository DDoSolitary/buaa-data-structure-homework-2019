#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
	char name[21], date[9];
	int nchildren, children[100], dep, type;
} nodes[100000];

char buf[21], target[21];
struct res_data {
	int id, path[200];
} res[100];
int nres, path[200];

void search(int id) {
	path[nodes[id].dep] = id;
	for (int i = 0; i < nodes[id].nchildren; i++) {
		int cid = nodes[id].children[i];
		if (nodes[cid].type == 0) {
			if (strcmp(target, nodes[cid].name) == 0) {
				res[nres].id = cid;
				for (int j = 0; j < nodes[cid].dep; j++) {
					res[nres].path[j] = path[j];
				}
				nres++;
			}
		} else {
			search(cid);
		}
	}
}

int cmp(const void *p, const void *q) {
	const struct res_data *a = p, *b = q;
	int r = strcmp(nodes[a->id].date, nodes[b->id].date);
	if (r != 0) return r;
	r = nodes[a->id].dep - nodes[b->id].dep;
	if (r != 0) return r;
	int dep = nodes[a->id].dep;
	for (int i = 0; i < dep; i++) {
		r = a->path[i] - b->path[i];
		if (r != 0) return r;
	}
	return 0;
}

int main() {
	int n;
	scanf("%s%d", target, &n);
	FILE *in = fopen("files.txt", "r");
	for (int i = 0; i < n; i++) {
		fscanf(in, "%s%s%d%s", nodes[i].name, buf, &nodes[i].type, nodes[i].date);
		for (int j = 0; j < i; j++) {
			if (nodes[j].type == 1 && strcmp(buf, nodes[j].name) == 0) {
				nodes[i].dep = nodes[j].dep + 1;
				nodes[j].children[nodes[j].nchildren++] = i;
			}
		}
	}
	strcpy(nodes[0].name + strlen(nodes[0].name), ":");
	search(0);
	qsort(res, nres, sizeof(struct res_data), cmp);
	for (int i = 0; i < nres; i++) {
		for (int j = 0; j < nodes[res[i].id].dep; j++) {
			printf("%s\\", nodes[res[i].path[j]].name);
		}
		printf("%s\n", nodes[res[i].id].name);
	}
}
