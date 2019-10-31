#include <stdio.h>
#include <string.h>
#define MAX(a,b) (a>b)?(a):(b)
#define NMAX 110
int n, sum = -100010, num, a[NMAX][NMAX], aLine[NMAX], bLine[NMAX];

void getNum()
{
	int i;
	num = bLine[0] = aLine[0];
	for (i = 1; i < n; i++)
	{
		bLine[i] = MAX(bLine[i - 1] + aLine[i], aLine[i]);
		if (bLine[i] > num)	num = bLine[i];
	}
}

int main()
{
	int i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			for (k = 0; k < n; k++)
				aLine[k] += a[j][k];
			getNum();
			sum = MAX(sum, num);
		}
		memset(aLine, 0, sizeof(aLine));
	}
	printf("%d\n", sum);
	return 0;
}