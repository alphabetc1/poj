#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

int ans[92][8] = { 0 }, num = 0, hang[8];

void queen(int i)
{
	int j, k;
	if (i == 8)
	{
		for (j = 0; j < 8; j++)
		{
			ans[num][j] = hang[j] + 1;
		}
		num++;
		return;
	}
	for (j = 0; j < 8; j++)
	{
		for (k = 0; k < i; k++)
			if (hang[k] == j || (k - i) == hang[k] - j || (i - k) == hang[k] - j)	break;
		if (i == k)
		{
			hang[i] = j;
			queen(i + 1);
		}
	}
}

int main()
{
	int i, n, b;
	queen(0);
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &b);
		for (i = 0; i < 8; i++)
		{
			printf("%d", ans[b - 1][i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}