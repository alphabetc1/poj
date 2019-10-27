#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
int count;

void decompose(int thres, int num)
{
	for (int i = thres; i <= num; i++)
	{
		if (i == num)
		{
			count++;
			return;
		}
		if (num % i == 0)	decompose(i, num / i);
	}
}

int main()
{
	int i, n, num;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &num);
		count = 0;
		decompose(2, num);
		printf("%d\n", count);
	}
	system("pause");
	return 0;
}