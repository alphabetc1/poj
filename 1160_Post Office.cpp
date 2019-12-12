/*dp[i][j]:ǰi����ׯ��j��վ������dis[i][j]��i��jֻ��1��վ����
��dp[i][j] = min(dp[i][j],dp[k][j-1]+dis[k+1][j])*/
#include <iostream>
#include <string>
#include <string.h>
#define MIN(a,b) (a<b)?(a):(b)
#define NMAX 310
using namespace std;

int a[NMAX], dp[NMAX][NMAX], dis[NMAX][NMAX];

int main() {
	int m, n, i, j, h, k, t, sum;
	cin >> n >> m;
	memset(dp, 0x3f, sizeof(dp));
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (i = 1; i <= n; i++) {						//��i��jֻ��1��վ�Ŀ���
		for (j = i + 1; j <= n; j++) {
			dis[i][j] = dis[i][j - 1] + a[j] - a[(i + j) / 2];
		}
		dp[i][1] = dis[1][i];
	}
	for (j = 2; j <= m; j++) {
		for (i = 1; i <= n; i++) {
			for (k = j - 1; k <= i - 1; k++) {
				dp[i][j] = MIN(dp[i][j], dp[k][j - 1] + dis[k + 1][i]);
			}
		}
	}
	cout << dp[n][m] << endl;
	system("pause");
	return 0;
}