#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
#define MIN(a,b) (a<b)?(a):(b)
using namespace std;

int a[NMAX], dp[NMAX][NMAX];

int main() {
	int i, j, k, n, t;
	memset(dp, 0x3f, sizeof(dp));
	cin >> n;
	for (i = 1; i <= n; i++)	cin >> a[i];
	for (k = 1; k < n; k++) {
		for (i = 1, j = i + k; j <= n; i++, j++) {
			if (j == i + 1)	dp[i][j] = 0;
			else {
				for (t = i + 1; t < j; t++) {
					dp[i][j] = MIN(dp[i][j], dp[i][t] + dp[t][j] + a[i] * a[t] * a[j]);
				}
			}
		}
	}
	cout << dp[1][n] << endl;
	system("pause");
	return 0;
}