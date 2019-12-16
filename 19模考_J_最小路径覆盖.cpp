//匈牙利算法求最短路径覆盖
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 510
using namespace std;

int n, m, link[NMAX], v[NMAX], a[NMAX][NMAX];

int find(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (a[x][i] && !v[i])
		{
			v[i] = 1;
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
	int i, j, left, right, sum, r;
	cin >> m >> n;
	sum = 0;
	memset(a, 0, sizeof(a));			//记得初始化数据
	memset(link, 0, sizeof(link));
	for (i = 1; i <= m; i++)
	{
		cin >> left >> right;
		a[left][right] = 1;
	}
	for (i = 1; i <= n; i++)
	{
		memset(v, 0, sizeof(v));	//每一轮清v，不要在回溯内部清v		
		sum += find(i);
	}
	cout << n - sum << endl;
	system("pause");
	return 0;
}