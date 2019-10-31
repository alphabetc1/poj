#include <stdio.h>
#include <string.h>
#define MAX(a, b) (a>b)?(a):(b)

int a[100010], d[100010], g[100010];

int main()
{
	int T, n, i, j, sum;
	scanf("%d", &T);
	while (T--)
	{
		sum = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 1; i < n; i++)
		{
			d[i] = MAX(a[i] - a[i - 1], d[i - 1] + a[i] - a[i - 1]);
		}
		for (i = 1; i < n; i++)
		{
			d[i] = MAX(d[i-1], d[i]);
		}
		g[1] = MAX(a[1] - a[0], 0);
		if (g[1] > sum)	sum = g[1];
		for (i = 2; i < n; i++)
		{
			g[i] = MAX(a[i] - a[i - 1] + d[i-2], g[i-1] + a[i] - a[i - 1]);
			if (g[i] > sum)	sum = g[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}
