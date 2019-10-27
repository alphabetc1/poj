#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#define N 105
using namespace std;

int n, m, in[N], temp[N];
char str[10], str1[30];
vector <int> G[N];
queue<int>q;

void init()
{
	memset(in, 0, sizeof(in));
	for (int i = 0; i <= n; i++)
		G[i].clear();
}

bool find(int u, int v)
{
	for (int i = 0; i < G[u].size(); i++)
		if (G[u][i] == v)	return true;
	return false;
}

int topoSort()
{
	int i, t, pos = 0, unsure = 0;
	while (!q.empty())	q.pop();
	for (i = 0; i < n; i++)
		if (!in[i])	q.push(i);
	while (!q.empty())
	{
		if (q.size() > 1)	unsure = 1;
		t = q.front();
		q.pop();
		str1[pos++] = t + 'A';
		for (i = 0; i < G[t].size(); i++)
		{
			if (--in[G[t][i]] == 0)	q.push(G[t][i]);
		}
	}
	if (pos < n)	return 1;
	else if (unsure)	return 2;
	else return 3;
}

int main()
{
	int i, j, flag, ok, k, src, des;
	while (scanf("%d %d", &n, &m) && n)
	{
		init();
		ok = false;
		flag = 2;
		for (i = 1; i <= m; i++)
		{
			scanf("%s", str);
			if (ok)	continue;
			src = str[0] - 'A';
			des = str[2] - 'A';
			if (!find(src, des))
			{
				G[src].push_back(des);
				in[des]++;
			}
			memcpy(temp, in, sizeof(in));
			flag = topoSort();
			memcpy(in, temp, sizeof(in));
			if (flag != 2)
			{
				k = i;
				ok = true;
			}
		}
		if (3 == flag)
		{
			printf("Sorted sequence determined after %d relations: ", k);
			for (i = 0; i < n; i++)
				printf("%c", str1[i]);
			printf(".\n");
		}
		else if (1 == flag)	printf("Inconsistency found after %d relations.\n", k);
		else printf("Sorted sequence cannot be determined.\n");
	}
	system("pause");
	return 0;
}