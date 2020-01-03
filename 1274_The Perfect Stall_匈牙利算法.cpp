//匈牙利算法求最大匹配
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 210
using namespace std;

int n, m, link[NMAX], used[NMAX], a[NMAX][NMAX];

int find(int x) {
	for (int i = 1; i <= m; i++) {				//别写成n
		if (a[x][i] && !used[i]) {
			used[i] = 1;
			if (!link[i] || find(link[i])) {
				link[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int i, j, num, right;
	while (cin >> n >> m) {						//多次数据
		memset(link, 0, sizeof(link));
		memset(a, 0, sizeof(a));
		for (i = 1; i <= n; i++) {
			cin >> num;
			for (j = 0; j < num; j++) {
				cin >> right;
				a[i][right] = 1;				//单向的，别写成a[i][right] = a[right][i] = 1;
			}
		}
		int ans = 0;
		for (i = 1; i <= n; i++) {
			memset(used, 0, sizeof(used));		//注意每轮清used
			ans += find(i);
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}
