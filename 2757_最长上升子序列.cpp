#include <iostream>
#include <string.h>
#define NMAX 1010
#define MAX(a,b) (a>b)?(a):(b)
using namespace std;

int main()
{
	int i, j, n, a[NMAX], maxLen[NMAX], ans = 1;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		maxLen[i] = 1;
	}
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] < a[i])	maxLen[i] = MAX(maxLen[i],maxLen[j]+1);
		}
		ans = MAX(ans, maxLen[i]);
	}
	cout << ans << endl;
	return 0;
}