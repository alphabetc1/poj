#include <stdio.h>
#include <string.h>
#define MIN(a,b) (a<b)?(a):(b)
#define INF 0x3f3f3f3f
#define NMAX 110

int a[NMAX], dp[NMAX][NMAX];

int getDp(int x, int y)
{
	if (dp[x][y] != INF)	return dp[x][y];
	if (y == x + 1)	dp[x][y] = 0;
	for (int k = x + 1; k < y; k++)
		dp[x][y] = MIN(dp[x][y], a[x] * a[k] * a[y] + getDp(x, k) + getDp(k, y));
	return dp[x][y];
}

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	memset(dp, 0x3f, sizeof(dp));
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", getDp(0, n - 1));
	return 0;
}