/*dp[i][u]表示前i个村庄建u个站的开销
**dis[i][j]从i到j只建1个站开销
**假定有6个村庄，村庄的坐标已知分别为p1,p2,p3,p4,p5,p6
**想求dis[1][4]的话邮局需要建立在2或者3处
**放在2处的消耗为：p4-p2+p3-p2+p2-p1=p4-p2+p3-p1，放在3处的结果为：p4-p3+p3-p2+p3-p1=p4+p3-p2-p1
**可见，将邮局建在2处或3处是一样的。
**现在接着求dis[1][5],现在处于中点的村庄是3，那么1-4到3的距离和刚才已经求出了，即为dis[1][4],所以只需再加上5到3的距离即可。
**同样，求dis[1][6]的时候也可以用dis[1][5]加上6到中点的距离。
**因此有递推关系：dis[i][j] = dis[i][j-1] + a[j] - a[(i+j)/2]
*/
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 310
#define MIN(a,b) (a<b)?(a):(b)
using namespace std;

int a[NMAX], dis[NMAX][NMAX], dp[NMAX][NMAX];

int main() {
	int i, j, t, u, n, k;
	cin >> n >> k;
	memset(dp, 0x3f, sizeof(dp));
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			dis[i][j] = dis[i][j - 1] + a[j] - a[(i + j) / 2];
		}
		dp[i][1] = dis[1][i];
	}
	for (u = 2; u <= k; u++) {
		for (i = 1; i <= n; i++) {
			for (j = u - 1; j <= i - 1; j++) {
				dp[i][u] = MIN(dp[j][u - 1] + dis[j + 1][i], dp[i][u]);
			}
		}
	}
	cout << dp[n][k] << endl;
	system("pause");
	return 0;
}
