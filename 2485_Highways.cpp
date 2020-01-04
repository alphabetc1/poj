#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#define MAX(a,b) (a>b)?(a):(b)
#define NMAX 510
using namespace std;

struct node {
	int u, v, cost;
}edge[50010];

int n, edgeNum, fa[NMAX], v[NMAX];

int cmp(const node a, const node b) {
	return a.cost < b.cost;
}

void init() {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
}

int find(int x)	{
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

int join(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		fa[x] = y;
		return 1;
	}
	return 0;
}

int getKruskal() {
	int x, y, num = 0, ans = 0;
	memset(v, 0, sizeof(v));
	for (int i = 0; i < edgeNum && num < n - 1; i++) {
		x = edge[i].u, y = edge[i].v;
		if (join(x, y)) {
			ans = MAX(ans, edge[i].cost);
			num++;
		}
	}
	return ans;
}

int main() {
	int t, cost;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		init();
		edgeNum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &cost);
				if (i < j) {
					edge[edgeNum].u = i;
					edge[edgeNum].v = j;
					edge[edgeNum].cost = cost;
					edgeNum++;
				}
			}
		}
		sort(edge, edge + edgeNum, cmp);
		printf("%d\n", getKruskal());
	}
	system("pause");
	return 0;
}