#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define NMAX 2010
#define GAP 7
using namespace std;

struct node {
	int u, v, cost;
}edge[2000010];

int n, edgeNum, fa[NMAX];
char str[NMAX][GAP];

int cmp(const node x, const node y) {
	return x.cost < y.cost;
}

void init() {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
}

int find(int x) {
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
	else return 0;
}

int countDif(int x, int y) {
	int sum = 0;
	for (int i = 0; i < GAP; i++)
		if (str[x][i] != str[y][i])	sum++;
	return sum;
}

void getEdge() {
	edgeNum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			edge[edgeNum].u = i;
			edge[edgeNum].v = j;
			edge[edgeNum].cost = countDif(i, j);
			edgeNum++;
		}
	}
	sort(edge, edge + edgeNum, cmp);
}

int getKruskal() {
	int num = 0, x, y, sum = 0;
	for (int i = 0; i < edgeNum && num < n - 1; i++) {
		x = edge[i].u, y = edge[i].v;
		if (join(x, y)) {
			sum += edge[i].cost;
			num++;
		}
	}
	return sum;
}

int main() {
	while (cin >> n && n) {
		init();
		for (int i = 1; i <= n; i++) {
			cin >> str[i];
		}
		getEdge();
		cout << "The highest possible quality is 1/" << getKruskal() << "." << endl;
	}
	system("pause");
	return 0;
}