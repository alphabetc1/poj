#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
int n, m;
char visit[25][25];

int f(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m)	return 0;
	else if (visit[x][y] == '#')	return 0;
	else
	{
		visit[x][y] = '#';
		return 1 + f(x - 1, y) + f(x + 1, y) + f(x, y - 1) + f(x, y + 1);
	}
}

int main()
{
	int i, j;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		memset(visit, 0, sizeof(visit));
		if (0 == n)	break;
		for (i = 0; i < n; i++)
		{
			scanf("%s", visit[i]);
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if ('@' == visit[i][j])
					printf("%d\n", f(i, j));
			}
		}
	}
	system("pause");
	return 0;
}