#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <math.h>

int ans;

void newCanGet(double *a, int num)
{
	int i, j, k, m;
	double b[4];
	if (fabs(a[0] - 24) < 0.0001 && num == 1 && a[0] > 0)	ans = 1;
	else if (num > 1)
	{
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				if (i == j)	continue;
				for (m = k = 0; k < num; k++)
				{
					if (k != i && k != j)
					{
						b[m++] = a[k];
					}
				}
				b[m] = a[i] + a[j];
				newCanGet(b, m + 1);
				b[m] = a[i] - a[j];
				newCanGet(b, m + 1);
				b[m] = a[i] * a[j];
				newCanGet(b, m + 1);
				if (a[j] != 0)
				{
					b[m] = a[i] / a[j];
					newCanGet(b, m + 1);
				}
			}
		}
	}
}

int main()
{
	double a[4];
	while (scanf("%lf%lf%lf%lf", &a[0], &a[1], &a[2], &a[3]))
	{
		if (a[0] + a[1] + a[2] + a[3] == 0)	break;
		ans = 0;
		newCanGet(a, 4);
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	system("pause");
	return 0;
}
