#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

char map[110][110];

int canGetout(int sx, int sy, int ex, int ey)
{
	if (sx == ex && sy == ey)	return 1;
	map[sx][sy] = '#';
	if (map[sx - 1][sy] == '.' && canGetout(sx-1, sy, ex, ey))	return 1;
	if (map[sx + 1][sy] == '.' && canGetout(sx + 1, sy, ex, ey))	return 1;
	if (map[sx ][sy - 1] == '.' && canGetout(sx, sy - 1, ex, ey))	return 1;
	if (map[sx][sy + 1] == '.' && canGetout(sx, sy + 1, ex, ey))	return 1;
	return 0;
}

int main()
{
	int n, m, i, j, start_x, start_y, end_x, end_y;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &m);
		for (i = 1; i <= m; i++)
		{
			getchar();
			for (j = 1; j <= m; j++)
			{
				scanf("%c", &map[i][j]);
			}
		}
		scanf("%d%d%d%d", &start_x, &start_y, &end_x, &end_y);
		if (map[start_x+1][start_y+1] == '#' || map[end_x+1][end_y+1] == '#' || !canGetout(start_x+1, start_y+1, end_x+1, end_y+1))
			printf("NO\n");
		else
			printf("YES\n");
	}
	system("pause");
	return 0;
}