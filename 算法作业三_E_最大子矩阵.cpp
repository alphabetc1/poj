//将二维问题转化为一维
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
#define MAX(a,b) (a>b)?(a):(b)
using namespace std;

int n, ans, aLink[NMAX], a[NMAX][NMAX];

void count() {
	int now = 0;
	for (int i = 1; i <= n; i++) {
		now += aLink[i];
		now = MAX(now, 0);
		ans = MAX(now, ans);
	}
}

int main() {
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	ans = 0;
	for (i = 1; i <= n; i++) {
		memset(aLink, 0, sizeof(aLink));
		for (j = i; j <= n; j++) {
			for (k = 1; k <= n; k++) {
				aLink[k] += a[j][k];
			}
			count();
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}
