#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#define INF 999999
using namespace std;


int n, fa[110], m, t, flag, k;
struct node {
	int u, v, cost, use;
}a[10010];

bool cmp(node a, node b)
{
	return a.cost < b.cost;
}

void init()
{
	for (int i = 1; i <= n; i++)
		fa[i] = i;
}

int find(int x)
{
	int r = x;
	while (r != fa[r])
		r = fa[r];
	int i = x, j;
	while (fa[i] != r)
	{
		j = fa[i];
		fa[i] = r;
		i = j;
	}
	return r;
}

int unite(int x, int y)
{
	int l = find(x), r = find(y);
	if (l != r)
	{
		fa[l] = r;
		return 1;
	}
	return 0;
}

int getNum(int x, int y)
{
	int sum = 0, cnt = 0;
	init();
	sort(a, a + n, cmp);
	for (int i = 0; i < m; i++)
	{
		if (a[i].u == x && a[i].v == y)	continue;
		if (find(a[i].u) != find(a[i].v))
		{
			cnt++;
			unite(a[i].u, a[i].v);
			sum += a[i].cost;
			if(!k)	a[i].use = 1;
		}
	}
	if(cnt == n-1)	return sum;
	else return INF;
}

int main()
{
	int i, j, sum, num, tag;
	scanf("%d", &t);
	while (t--)
	{
		sum = num = flag = k = 0;
		memset(a, 0, sizeof(a));
		scanf("%d %d", &n, &m);
		init();
		for (i = 0; i < m; i++)
		{
			scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].cost);
		}
		sum = getNum(n+1, n+1);
		k = 1;
		for (i = 0; i < m; i++)
		{
			if (a[i].use == 1)
			{
				num = getNum(a[i].u, a[i].v);
				if (num == sum)	flag = 1;		
			}
		}
		if (flag)	printf("Not Unique!\n");
		else printf("%d\n", sum);
	}
	system("pause");
	return 0;
}