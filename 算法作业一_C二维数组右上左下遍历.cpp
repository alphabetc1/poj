#include <stdio.h>
#include <string>
int main()
{
	int i, j, x, y, ymax = -1, n, m, tag = 0, a[110][110];
	x = y = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}
	while (1)
	{
		if (y == m-1)	tag++;
		if (y > ymax)	ymax = y;
		printf("%d\n", a[x][y]);
		if (x == n - 1 && y == m - 1)	break;
		if (y == 0 || x == n - 1)
		{
			x = tag;
			y = ymax < m - 1 ? ymax + 1 : m - 1;
		}
		else
		{
			x++;
			y--;
		}
	}
	system("pause");
	return 0;
}