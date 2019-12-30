#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
#define MIN(a,b) (a<b)?(a):(b)
using namespace std;

int a[NMAX], dp[NMAX][NMAX];

int main() {
	int n, i, j, k, t;
	cin >> n;
	memset(dp, 0x3d, sizeof(dp));
	for (i = 1; i <= n; i++) {	
			cin >> a[i];
	}
	for (t = 1; t < n; t++) {
		for (i = 1, j = i+t; j <= n; i++, j++) {
			if (j == i + 1) {
				dp[i][j] = 0;
			}
			for (k = i + 1; k < j; k++) {
				dp[i][j] = MIN(dp[i][j], a[i] * a[k] * a[j] + dp[i][k] + dp[k][j]);
			}
		}
	}
	cout << dp[1][n] << endl;
	system("pause");
	return 0;
}
