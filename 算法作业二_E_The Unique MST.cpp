/*题意：给出一个图，判断图是否具有唯一的最小生成树
**先求出MST，标记树上的边
**依次删去每条边，看剩下的图是否能产生与之前相同的MST*/
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define NMAX 100010
using namespace std;

struct node {
	int s, t, cost, use, invalue;		//use和invalue分别标记原MST是否使用和本轮是否可用
}edge[NMAX];

int n, m, cost, minCost, flag, first, fa[NMAX], v[NMAX];	

void init() {
	cost = 0;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
}

int cmp(const node p1, const node p2) {
	return p1.cost < p2.cost;
}

int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y)	fa[x] = y;
}

int detectUse() {
	for (int i = 1; i <= n; i++) {
		if (!v[i])	return 0;
	}
	return 1;
}

void getConnect() {
	memset(v, 0, sizeof(v));
	for (int i = 0; i < m; i++) {
		if (!edge[i].invalue) {
			int x = find(edge[i].s), y = find(edge[i].t);
			if (x != y) {
				join(x, y);
				v[edge[i].s] = v[edge[i].t] = 1;
				cost += edge[i].cost;
				if (!first) {		//只有第一轮可以标记原MST是否使用一条边
					edge[i].use = 1;
				}
			}
		}
	}
}

int main() {
	int i, j, t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		init();
		first = minCost = flag = 0;
		memset(edge, 0, sizeof(edge));
		for (i = 0; i < m; i++) {
			cin >> edge[i].s >> edge[i].t >> edge[i].cost;
		}
		sort(edge, edge + n, cmp);
		getConnect();
		minCost = cost;
		first = 1;
		for (i = 0; i < m; i++) {
			if (edge[i].use) {
				edge[i].invalue = 1;
				init();
				getConnect();
				if (cost == minCost && detectUse()) {
					flag = 1;
				}
				edge[i].invalue = 0;
			}
		}
		if (flag) {
			cout << "Not Unique!" << endl;
		}
		else {
			cout << minCost << endl;
		}
	}
	system("pause");
	return 0;
}
