#include <stdio.h>
#include <string>
void findpath(int, int, int ,int);
int n = 1, a[110], b[110];
int main()
{
	int i;
	while (scanf("%d", &a[n]) != EOF && a[n] != -1)
		n++;
	n /= 2;
	for (i = 1; i <= n ; i++)
	{
		b[i] = a[n + i];
		a[n + i] = 0;
	}
	findpath(1, n, 1, n);
	system("pause");
	return 0;
}

void findpath(int starta, int enda, int startb, int endb)
{
	int i;
	if (starta > enda)	return;
	printf("%d ", b[endb]);
	for (i = starta; i <= enda && a[i] != b[endb]; i++);
	findpath(starta, i - 1, startb, startb + i - starta - 1);
	findpath(i+1, enda, startb+i - starta, endb-1);
}