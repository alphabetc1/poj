/*dp[i][j]的含义是a中前i个和b中前j个且包含b[j]的最长公共上升序列长度
**二维数组pre记载路径
**在poj上A了，到百练/NOI就WA，不懂。。。*/
#include <iostream>
#include <string.h>
#define NMAX 510
using namespace std;

typedef long long LL;
LL a[NMAX], b[NMAX], res[NMAX];
int n, m, pre[NMAX][NMAX], dp[NMAX][NMAX];

void getRes() {
	memset(dp, 0, sizeof(dp));
	memset(pre, 0, sizeof(pre));
	for (int i = 1; i <= n; i++) {
		int k = 0;
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			if (a[i] > b[j] && dp[i][j] > dp[i][k])	k = j;
			else if (a[i] == b[j]) {
				pre[i][j] = k;
				dp[i][j] = dp[i][k] + 1;
			}
		}
	}
	int maxj = 1;
	for (int j = 2; j <= m; j++)
		if (dp[n][j] > dp[n][maxj]) maxj = j;
	cout << dp[n][maxj] << endl;
	int x = n, y = maxj, ans = 0;;
	while (dp[x][y]) {
		if (a[x] != b[y])	x--;
		else {
			res[ans++] = a[x];
			y = pre[x][y];
		}
	}
	if (!ans)	cout << endl;
	for (int i = ans - 1; i >= 0; i--)
		cout << res[i] << " ";
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++)	cin >> b[i];
	getRes();
	return 0;
}