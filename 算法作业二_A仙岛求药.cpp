#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
#include <functional>
#define INF 999999
using namespace std;
int vis[25][25];
char map[25][25];
int fw[4][2] = { { 0, -1 },{ -1, 0 },{ 0, 1 },{ 1, 0 } };

struct node {
	int x, y, sum;
	bool operator > (const node & e) const {
		return sum > e.sum;
	}
};

priority_queue<node, vector<node>, greater<node> > q;

int main()
{
	int i, j, n, m, min, flag;
	node start, np;
	while (scanf("%d %d", &n, &m) && n != 0)
	{
		while (!q.empty()) q.pop();
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		min = -1;
		flag = 0;
		for (i = 1; i <= n; i++)
		{
			getchar();
			for (j = 1; j <= m; j++)
			{
				scanf("%c", &map[i][j]);
				if (map[i][j] == '@')
				{
					start.x = i;
					start.y = j;
					start.sum = 0;
					q.push(start);
					vis[i][j] = 1;
				}
			}
		}
		while (!q.empty() && !flag)
		{
			start = q.top();
			q.pop();
			for (i = 0; i < 4 && !flag; i++)
			{
				np.x = start.x + fw[i][0];
				np.y = start.y + fw[i][1];
				np.sum = start.sum + 1;
				if (np.x < 1 || np.x > n || np.y < 1 || np.y > m);
				else if (map[np.x][np.y] == '*')
				{
					flag = 1;
					min = np.sum;
				}
				else if (!vis[np.x][np.y] && map[np.x][np.y] != '#')
				{
					q.push(np);
					vis[np.x][np.y] = 1;
				}
			}
		}
		printf("%d\n", min);
	}
	system("pause");
	return 0;
}