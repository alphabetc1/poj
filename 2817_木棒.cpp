#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

int stocks[110], used[110];

int compare(const void *p1, const void *p2)
{
	return *(int*)p2 - *(int*)p1;
}

int canJoint(int totalSize, int nowSize, int left, int len)
{
	if (nowSize == 0 && left == 0)	return 1;
	if (left == 0)	left = len;
	for (int i = 1; i <= totalSize; i++)
	{
		if (used[i] == 1)	continue;
		if (stocks[i] > left)	continue;
		used[i] = 1;
		if (canJoint(totalSize, nowSize - 1, left - stocks[i], len))
			return 1;
		used[i] = 0;
		if (stocks[i] == left || left == len)	break;
	}
	return 0;
}

int main()
{
	int n, i, sum;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)	break;
		sum = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &stocks[i]);
			sum += stocks[i];
		}
		qsort(stocks + 1, n, sizeof(int), compare);
		for (i = stocks[1]; i <= sum; i++)
		{
			if (sum % i != 0)	continue;
			memset(used, 0, sizeof(used));
			if (canJoint(n, n, 0, i))
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	system("pause");
	return 0;
}