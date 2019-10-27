#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

int getSum(int x, int y)
{
	if (x == 0 || y == 1)	return 1;
	else if (x < y)	return getSum(x, x);
	else return getSum(x, y - 1) + getSum(x - y, y);
}

int main()
{
	int n, apple, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &apple, &temp);
		printf("%d\n", getSum(apple, temp));
	}
	system("pause");
	return 0;
}