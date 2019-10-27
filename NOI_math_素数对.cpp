#include <stdio.h>
#include <string>
#include <math.h>

int isprime(int x)
{
	for (int i = 2; i < sqrt(x) + 1; i++)
	{
		if (0 == x % i)	return 0;
	}
	return 1;
}
int main()
{
	int n, flag = 0;
	scanf("%d", &n);
	for (int i = 2; i <= n - 2; i++)
	{
		if (isprime(i) && isprime(i + 2))
		{
			printf("%d %d\n", i, i + 2);
			flag = 1;
		}
	}

	if (0 == flag)	printf("empty\n");
	system("pause");
	return 0;
}