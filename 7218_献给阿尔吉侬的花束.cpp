#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <queue>
using namespace std;
int visit[210][210], r, c, sx, sy, ex, ey, dr1[4] = { 0, 0, 1, -1 }, dr2[4] = {1, -1, 0, 0}, sum;
char map[210][210];

typedef struct Node {
	int x, y;
	int num;
};
queue<Node>q;
void bfs()
{
	Node now, next;
	now.x = sx, now.y = sy, now.num = 0;
	while (!q.empty())q.pop();
	q.push(now);
	visit[sx][sy] = 1;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if (map[now.x][now.y] == 'E')
		{
			sum = now.num;
			return;
		}
		next.num = now.num + 1;
		for (int i = 0; i < 4; i++)
		{
			next.x = now.x + dr1[i];
			next.y = now.y + dr2[i];
			if (next.x >= 1 && next.x <= r && next.y >= 1 && next.y <= c && !visit[next.x][next.y] && map[next.x][next.y] == '.' || map[next.x][next.y] == 'E')
			{
				visit[next.x][next.y] = 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	int i, j, T;
	scanf("%d", &T);
	while (T--)
	{
		sum = 0;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		scanf("%d %d", &r, &c);
		for (i = 1; i <= r; i++)
		{
			getchar();
			for (j = 1; j <= c; j++)
			{
				scanf("%c", &map[i][j]);
				if (map[i][j] == 'S')
				{
					sx = i, sy = j;
				}
			}
		}
		bfs();
		if (sum == 0)	printf("oop!\n");
		else printf("%d\n", sum);
	}
	system("pause");
	return 0;
}