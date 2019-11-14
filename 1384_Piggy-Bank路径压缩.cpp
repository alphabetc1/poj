#include <stdio.h>
#include <string>
#include <string.h>
#define MIN(a,b) (a<b)?(a):(b)
#define INF 0x3f3f3f3f
#define NMAX 510
using namespace std;
int w[NMAX], p[NMAX], v[20110];

int main()
{
	int T, i, j, wN, wM, k;
	scanf("%d", &T);
	while (T--)
	{
		memset(v, 0x3f, sizeof(v));
		scanf("%d%d%d", &wN, &wM, &k);
		wM -= wN;
		for (i = 0; i < k; i++)
			scanf("%d%d", &p[i], &w[i]);
		for (i = 0; w[0] * i <= wM; i++)
			v[wM - w[0] * i] = p[0] * i;
		for (i = 1; i < k; i++)
			for (j = wM; j >= 0; j--)
			{
				v[j] = MIN(v[j], p[i] + v[j + w[i]]);
			}
		if (v[0] != INF)	printf("The minimum amount of money in the piggy-bank is %d.\n", v[0]);
		else printf("This is impossible.\n");
	}
	system("pause");
	return 0;
}