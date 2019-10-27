#include <stdio.h>
#include <string>
#include <string.h>
int a[100100];

int main()
{
	int i, j, n, left = 100100, right = 0, x, y, flag = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		x *= 10;
		y *= 10;
		if (x < left) left = x;
		if (y > right)right = y;
		for (j = x; j <= y; j += 5)
		{
			a[j] = 1;
		}
	}
	for (i = left; i <= right; i += 5)
		if (!a[i])	flag = 1;
	if (1 == flag)	printf("no\n");
	else printf("%d %d\n", left / 10, right / 10);
	system("pause");
	return 0;
}