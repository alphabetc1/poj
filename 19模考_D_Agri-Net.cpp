#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <functional>
#define NMAX 110
using namespace std;

struct node {
	int cow, row, cost;
	bool operator > (const node &e)	const {
		return cost > e.cost;
	}
}nw;

int n, fa[NMAX], a[NMAX][NMAX];
priority_queue<node, vector<node>, greater<node>>q;

void init() {
	for (int i = 0; i < n; i++)
		fa[i] = i;
}

int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

void join(int x, int y) {
	x = find(x), y = find(y);
	if (x != y)
		fa[x] = y;
}

int main() {
	int i, j, sum;
	while (cin >> n) {
		sum = 0;
		init();
		while (!q.empty())	q.pop();
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				cin >> a[i][j];
				if (i != j) {
					nw.cow = i, nw.row = j, nw.cost = a[i][j];
					q.push(nw);
				}
			}
		for (i = 0; i < n - 1; ) {
			nw = q.top(), q.pop();
			if (find(nw.cow) != find(nw.row)) {
				join(nw.cow, nw.row);
				sum += nw.cost;
				i++;
			}
		}
		cout << sum << endl;
	}

	system("pause");
	return 0;
}