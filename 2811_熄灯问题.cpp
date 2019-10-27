#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

int light[6][8], press[6][8];

int guess()
{
	int i, j;
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 7; j++)
		{
			press[i+1][j] = (press[i - 1][j] + press[i][j + 1] + press[i][j - 1] + press[i][j] + light[i][j]) % 2;
		}
	}
	for (j = 1; j < 7; j++)
	{
		if (((press[5][j - 1] + press[5][j] + press[5][j + 1] + press[4][j]) % 2) != light[5][j])	return -1;
	}
	return 0;
}

void getPress()
{
	int i;
	while (guess())
	{
		press[1][1]++;
		i = 1;
		while (press[1][i] > 1)
		{
			press[1][i] = 0;
			i++;
			press[1][i]++;
		}
	}
}

int main()
{
	int i, j, k;
	memset(press, 0, sizeof(press));
	for (i = 1; i < 6; i++)
	{
		for (j = 1; j < 7; j++)
		{
			scanf("%d", &light[i][j]);
		}
	}
	getPress();
	for (i = 1; i < 6; i++)
	{
		for (j = 1; j < 7; j++)
		{
			printf("%d ", press[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}