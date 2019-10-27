#include <stdio.h>
#include <string>
#include <string.h>
char map[10][10];
int n, m, total, count, hang[10];

void dfs(int cow, int num)
{
	if (num == total)
	{
		count++;
		return;
	}
	if (cow >= n)	return;
	for (int i = 0; i < n; i++)
	{
		if (hang[i] == 0 && map[cow][i] == '#')
		{
			hang[i] = 1;
			dfs(cow + 1, num + 1);
			hang[i] = 0;
		}
	}
	dfs(cow + 1, num);
}

int main()
{
	while (scanf("%d %d", &n, &total) && n != -1)
	{
		memset(hang, 0, sizeof(hang));
		memset(map, 0, sizeof(map));
		count = 0;
		getchar();
		for (int i = 0; i < n; i++)
			scanf("%s", map[i]);
		dfs(0, 0);
		printf("%d\n", count);
	}
	system("pause");
	return 0;
}