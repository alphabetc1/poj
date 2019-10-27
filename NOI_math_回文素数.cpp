#include <stdio.h>
#include <string>
#include <math.h>

int visit[10000];
int getHuiwen(int x)
{
	int k,tmp = x,sum = 0;
	while (tmp)
	{
		k = tmp % 10;
		tmp /= 10;
		sum = sum * 10 + k;
	}
	if (x == sum)	return 1;
	return 0;
}

int isPrime(int x)
{
	if (x == 1)return 0;
	if (x == 2)return 1;
	for (int i = 2; i < sqrt(x) + 1; i++)
	{
		if (0 == x % i)	return 0;
	}
	return 1;
}

int main()
{
	int k, sum = 0,m = 1;
	scanf("%d", &k);
	for (int i = 1; i < k; i++) m *= 10;
	for (int i = m; i < m*10; i++)
	{
		if (isCle(i) && isPrime(i))
		{
			visit[sum++] = i;
		}
	}
	printf("%d\n", sum);
	for (int i = 0; i < sum; i++)
	{
		//printf("%d ", visit[i]);
	}

	system("pause");
	return 0;
}