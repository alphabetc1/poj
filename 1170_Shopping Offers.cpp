#include <iostream>
#include <string>
#include <string.h>
#define NMAX 7
#define MIN(a,b) (a<b)?(a):(b)
using namespace std;

struct node {
	int cost, num, c_get[NMAX], k_get[NMAX], tag[NMAX];
}edge[110];

int vis[1010], v[NMAX], c[NMAX], k[NMAX], value[NMAX][NMAX][NMAX][NMAX][NMAX];

int main()
{
	int i, j, n, m, cmp = 1;
	memset(value, 0x3f, sizeof(value));
	value[0][0][0][0][0] = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> edge[i].c_get[0] >> k[i+1] >> edge[i].cost;
		edge[i].k_get[0] = edge[i].num = 1;
		if (!vis[edge[i].c_get[0]])
		{
			vis[edge[i].c_get[0]] = edge[i].tag[0] = cmp;
			cmp++;
		}
		else
			edge[i].tag[0] = vis[edge[i].c_get[0]];
	}
	cin >> m;
	for (i = n; i < m + n; i++)
	{
		cin >> edge[i].num;
		for (j = 0; j < edge[i].num; j++)
		{
			cin >> edge[i].c_get[j] >> edge[i].k_get[j];
			if (!vis[edge[i].c_get[j]])
			{
				vis[edge[i].c_get[j]] = edge[i].tag[j] = cmp;
				cmp++;
			}
			else
				edge[i].tag[j] = vis[edge[i].c_get[j]];
		}
		cin >> edge[i].cost;
	}
	for (i = 0; i < n + m; i++)
	{
		memset(c, 0, sizeof(c));
		for (j = 0; j < edge[i].num; j++)
		{
			c[edge[i].tag[j]] = edge[i].k_get[j];
		}
		for (v[1] = c[1]; v[1] <= k[1]; v[1]++)
			for (v[2] = c[2]; v[2] <= k[2]; v[2]++)
				for (v[3] = c[3]; v[3] <= k[3]; v[3]++)
					for (v[4] = c[4]; v[4] <= k[4]; v[4]++)
						for (v[5] = c[5]; v[5] <= k[5]; v[5]++)
						{
							value[v[1]][v[2]][v[3]][v[4]][v[5]] = MIN(value[v[1]][v[2]][v[3]][v[4]][v[5]], value[v[1] - c[1]][v[2] - c[2]][v[3] - c[3]][v[4] - c[4]][v[5] - c[5]] + edge[i].cost);
						}
	}
	cout << value[k[1]][k[2]][k[3]][k[4]][k[5]] << endl;
	system("pause");
	return 0;
}