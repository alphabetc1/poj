#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#define MIN(a,b) (a<b)?(a):(b)
#define NMAX 210
#define INF 0x3f3f3f3f
using namespace std;
//EK网络流算法
int n, m, ans, pre[NMAX], a[NMAX], cap[NMAX][NMAX], flow[NMAX][NMAX];

void ek(int st, int en)	{
	int i, u, v;
	queue<int>q;
	while (1) {
		memset(a, 0, sizeof(a));
		a[st] = INF;
		q.push(st);
		while (!q.empty()) {
			u = q.front(), q.pop();
			for (v = 1; v <= m; v++) {			//注意一定是m，因为m是汇点，不能从m再流出去
				if (!a[v] && cap[u][v] > flow[u][v]) {
					q.push(v);
					pre[v] = u;
					a[v] = MIN(a[u], (cap[u][v] - flow[u][v]));
				}
			}
		}
		if (!a[en])	break;
		for (i = en; i != st; i = pre[i]) {
			flow[pre[i]][i] += a[en];
			flow[i][pre[i]] -= a[en];
		}
		ans += a[en];
	}
	cout << ans << endl;
}

int main()	{
	int i, x, y, c;
	while (cin >> n >> m)
	{
		ans = 0;
		memset(flow, 0, sizeof(flow));
		memset(cap, 0, sizeof(cap));
		for (i = 0; i < n; i++)
		{
			cin >> x >> y >> c;
			cap[x][y] += c;
		}
		ek(1, m);
	}
	system("pause");
	return 0;
}