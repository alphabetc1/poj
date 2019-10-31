#include <stdio.h>
#include <string.h>
#include <math.h>
#define MIN(a,b) (a<b)?(a):(b)
#define NMAX 1010
//这题数据规模小所以可以暴力，题号3658会放二分法求最近点对

int n;
double dis, num, sx[NMAX], sy[NMAX], ax[NMAX], ay[NMAX];

int main()
{
	int T, i, j;
	scanf("%d", &T);
	while (T--)
	{
		dis = 10000000000;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%lf %lf", &sx[i], &sy[i]);
		for (i = 0; i < n; i++)
			scanf("%lf %lf", &ax[i], &ay[i]);
		for(i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				num = sqrt((sx[i] - ax[j])*(sx[i] - ax[j]) + (sy[i] - ay[j])*(sy[i] - ay[j]));
				dis = MIN(dis, num);
			}
		printf("%.3lf\n", dis);
	}
	return 0;
}