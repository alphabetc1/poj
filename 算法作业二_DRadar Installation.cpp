#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

typedef struct node {
	double start, end;
};

node a[1010];

int cmp(const node p1, const node  p2)
{
	if (p1.start == p2.start)	return p1.end > p2.end;
	return p1.start < p2.start;
}

int main()
{
	int i, j, n, m, t = 1, num, flag;
	double x, y, times;
	while (scanf("%d %d", &n, &m) && n != 0)
	{
		flag = 0;
		memset(a, 0, sizeof(a));
		for(i = 0; i < n; i++)
		{
			scanf("%lf %lf", &x, &y);
			if (y < 0) y = -y;
			if (y > m)		flag = 1;
			if (!flag)
			{
				a[i].start = x - sqrt(m*m - y * y);
				a[i].end = x + sqrt(m*m - y * y);
			}
		}
		sort(a, a+n, cmp);
		num = -1;
		if (!flag)
		{
			num = 1;
			times = a[0].end;
			for (i = 1; i < n; i++)
			{
				if (a[i].start > times)
				{
					num++;
					times = a[i].end;
				}
				else if (a[i].end < times)
					times = a[i].end;
			}
		}
		printf("Case %d: %d\n", t++, num);
	}
	system("pause");
	return 0;
}