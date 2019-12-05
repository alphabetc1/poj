#include <iostream>
#include <string>
#include <string.h>
#define NMAX 210
using namespace std;

int n, m, link[NMAX], used[NMAX], a[NMAX][NMAX];
//匈牙利算法
int find(int x)
{
	for (int i = 1; i <= m; i++)
	{
		if (a[x][i] && !used[i])
		{
			used[i] = 1;
			if (!link[i] || find(link[i]))
			{
				link[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, k, sum, r;
	while (cin >> n >> m)
	{
		sum = 0;
		memset(a, 0, sizeof(a));			//记得初始化数据
		memset(link, 0, sizeof(link));
		for (i = 1; i <= n; i++)
		{
			cin >> k;
			for (j = 0; j < k; j++)
			{
				cin >> r;
				a[i][r] = 1;				//写a[i][r] = a[r][i] = 1就错了
			}
		}
		for (i = 1; i <= n; i++)
		{
			memset(used, 0, sizeof(used));	//每一轮清used，不要在回溯内部清used
			sum += find(i);
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}