//遇到不同格子增加跳数不同的时候，不能直接简单BFS，因为会打乱顺序(队列中跳数大的在跳数小的前面) 
//此时用 优先级队列 或者 简单BFS + 停顿
#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <functional>
#define NMAX 210
#define INF 0x3f3f3f3f
#define MIN(a,b) (a<b)?(a):(b)
using namespace std;

struct node {
	int cow, row, cost;
};
int sum, sc, sr, n, m, fw[4][2] = { { -1, 0 } ,{ 1, 0 } ,{ 0,1 } ,{ 0,-1 } }, vis[NMAX][NMAX];
char map[NMAX][NMAX];

int bfs() {
	node nw, nd;
	queue<node>q;
	nw.cow = sc, nw.row = sr, nw.cost = 0;
	memset(vis, 0, sizeof(vis));
	vis[sc][sr] = 1;
	sum = INF;
	q.push(nw);
	while (!q.empty()) {
		nw = q.front(), q.pop();
		if (map[nw.cow][nw.row] == 'x') {
			map[nw.cow][nw.row] = '@';
			nw.cost++;
			q.push(nw);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			nd.cow = nw.cow + fw[i][0];
			nd.row = nw.row + fw[i][1];
			if (vis[nd.cow][nd.row] || nd.cow < 0 || nd.cow >= n || nd.row < 0 || nd.row >= m)	continue;
			switch (map[nd.cow][nd.row]) {
			case '@':
			case 'x':nd.cost = nw.cost + 1;
				q.push(nd);
				vis[nd.cow][nd.row] = 1;
				break;
			case 'a':sum = nw.cost + 1;
				return 1;
			default:break;
			}
		}
	}
	return 0;
}

int main() {
	int t, i, j;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'r') {
					sc = i, sr = j;
				}
			}
		if (bfs())	cout << sum << endl;
		else cout << "Impossible" << endl;
	}
	system("pause");
	return 0;
}