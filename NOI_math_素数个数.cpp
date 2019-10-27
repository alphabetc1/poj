#include <stdio.h>
#include <string>
#include <math.h>
#define max(a,b) (a>=b?a:b)
#define min(a,b) (a>=b?b:a)

int isprime(int x)
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
	int m, n, sum = 0;
	scanf("%d%d", &m, &n);
	for (int i = min(m,n); i <= max(m,n); i++)
	{
		if (isprime(i))
		{
			sum++;
		}
	}
	
	printf("%d\n",sum);
	system("pause");
	return 0;
}