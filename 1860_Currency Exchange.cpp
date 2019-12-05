#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
#define MIN(a,b) (a<b)?(a):(b)
using namespace std;
//bell-fordmanËã·¨
struct node {
	int u, v;
	double r, c;
}edge[2 * NMAX];

double sum, value[NMAX];

int main()
{
	int i, j, k, x, y, n, m, start, flag = 0, update = 1;
	cin >> n >> m >> start >> sum;
	for (i = 0; i < m; i++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].r >> edge[i].c >> edge[i + m].r >> edge[i + m].c;
		edge[i + m].v = edge[i].u, edge[i + m].u = edge[i].v;
	}
	memset(value, 0, sizeof(value));
	value[start] = sum;
	while (update)
	{
		update = 0;
		for (j = 0; j < 2 * m; j++)
		{
			if ((value[edge[j].u] - edge[j].c)*edge[j].r > value[edge[j].v])
			{
				update = 1;
				value[edge[j].v] = (value[edge[j].u] - edge[j].c)*edge[j].r;
			}
			if (value[start] > sum)
			{
				flag = 1;
				update = 0;
			}
		}
	}

	if (flag)	cout << "YES" << endl;
	else cout << "NO" << endl;
	system("pause");
	return 0;
}