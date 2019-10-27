#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

int room[60][60], visit[60][60] = { 0 };
int rooms, n, m;

int searchRoom(int i, int j)
{
	if (i > n || i < 1 || j >m || j < 1)	return 0;
	if ((room[i][j] & 1) == 0 && !visit[i][j-1])
	{
		rooms++;
		visit[i][j - 1] = 1;
		searchRoom(i, j-1);
	}
	if ((room[i][j] & 2) == 0 && !visit[i-1][j])
	{
		rooms++;
		visit[i - 1][j] = 1;
		searchRoom(i - 1, j);
	}
	if ((room[i][j] & 4) == 0 && !visit[i][j + 1])
	{
		rooms++;
		visit[i][j+1] = 1;
		searchRoom(i, j+1);
	}
	if ((room[i][j] & 8) == 0 && !visit[i+1][j])
	{
		rooms++;
		visit[i+1][j] = 1;
		searchRoom(i +1, j);
	}
	return rooms;
}

int main()
{
	int i, j, count = 0, max = 0, num;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &room[i][j]);
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (visit[i][j] == 0)
			{
				rooms = 1;
				visit[i][j] = 1;
				count++;
				num = searchRoom(i, j);
				if (num > max)	max = num;
			}
		}
	}
	printf("%d\n%d\n", count, max);
	system("pause");
	return 0;
}