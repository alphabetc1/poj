#include <stdio.h>
#include <string>

int gcd(int x, int y)
{
	if (y == 0)return x;
	else return gcd(y, x%y);
}

int lcd(int x, int y)
{
	return x * y / gcd(x, y);
}

int main()
{
	int g, l, j, sum, tmp;
	while (scanf("%d%d", &g, &l) != EOF)
	{
		sum = g + l;
		for (int i = g; i < l/2; i += g)
		{
			if (g * l % i != 0)continue;
			j = g * l / i;
			if (g == gcd(i, j) && l == lcd(i, j))
				if (i + j < sum)
					sum = i + j;
		}
		printf("%d\n", sum);
	}
	system("pause");
	return 0;
}