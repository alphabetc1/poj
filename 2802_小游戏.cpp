#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

int sum, cutNum, max, printNum, a[6], b[6];

void getCut(int num, int nowNum, int getNum)
{
	if (nowNum + num == max)
	{
		cutNum++;
		return;
	}
	if (nowNum + num > max && nowNum + num <= sum)
	{
		cutNum = 1;
		max = nowNum + num;
		a[getNum++] = num;
		memcpy(b, a, sizeof(a));
		printNum = getNum;
		return;
	}
	for (int k = 10; num >= k; k *= 10)
	{
		a[getNum] = num % k;
		getCut(num / k, nowNum + num % k, getNum + 1);
	}
}

int main()
{
	int num, i;
	while (scanf("%d%d", &sum, &num) != EOF)
	{
		if (sum == 0)	break;
		cutNum = 0;
		max = 0;
		getCut(num, 0, 0);
		if (0 == cutNum)	printf("error\n");
		else if (cutNum > 1)	printf("rejected\n");
		else
		{
			printf("%d", max);
			for (i = printNum - 1; i >=0 ; i--)
				printf(" %d", b[i]);
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
