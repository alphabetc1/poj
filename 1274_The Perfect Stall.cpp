#include <iostream>
#include <string>
#include <string.h>
#define NMAX 210
using namespace std;

int n, m, link[NMAX], used[NMAX], a[NMAX][NMAX];
//�������㷨
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
		memset(a, 0, sizeof(a));			//�ǵó�ʼ������
		memset(link, 0, sizeof(link));
		for (i = 1; i <= n; i++)
		{
			cin >> k;
			for (j = 0; j < k; j++)
			{
				cin >> r;
				a[i][r] = 1;				//дa[i][r] = a[r][i] = 1�ʹ���
			}
		}
		for (i = 1; i <= n; i++)
		{
			memset(used, 0, sizeof(used));	//ÿһ����used����Ҫ�ڻ����ڲ���used
			sum += find(i);
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}