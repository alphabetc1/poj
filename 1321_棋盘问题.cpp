#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <math.h>

int n, pieceNum, count, m;
char map[10][10];
int hang[10];

void dfs(int cur)
{
	if (m == pieceNum)
	{
		count++;
		return;
	}
	if (cur >= n)	return;
	for (int j = 0; j < n; j++)
	{
		if (hang[j] == 0 && map[cur][j] == '#')
		{
			hang[j] = 1;
			m++;
			dfs(cur + 1);
			hang[j] = 0;
			m--;
		}
	}
	dfs(cur + 1);
}

int main()
{
	int  i, j, base;
	while (scanf("%d%d", &n, &pieceNum) && n != -1)
	{
		memset(map, 0, sizeof(map));
		memset(hang, 0, sizeof(hang));
		count = 0;
		m = 0;
		getchar();
		for (i = 0; i < n; i++)
		{
			scanf("%s", map[i]);
		}
		dfs(0);
		printf("%d\n", count);
	}
	system("pause");
	return 0;
}
