/*匈牙利算法求最大独立集
**成员总数-最大匹配数量=最大独立集中的成员个数
**匈牙利算法的主动匹配点是没法重复利用的，只有被匹配点可以更换匹配
**所以用used数组来区别已经主动匹配过的点
*/
#include <iostream>
#include <string>
#include <string.h>
#define INF 0x3f3f3f3f
#define NMAX 510
using namespace std;

int n, used[NMAX], v[NMAX], link[NMAX], a[NMAX][NMAX];

int find(int x) {
	for (int i = 0; i < n; i++) {
		if (!v[i] && a[x][i]) {
			v[i] = 1;
			if (!used[i] && (link[i] == INF || find(link[i]))) {	//该点还没有主动匹配过
				link[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int i, j, left, right, num, sum;
	char tmp;
	while (cin >> n) {
		sum = 0;
		memset(a, 0, sizeof(a));
		memset(link, 0x3f, sizeof(link));
		memset(used, 0, sizeof(used));
		for (i = 0; i < n; i++) {
			cin >> left >> tmp>>tmp>>num>>tmp;
			for (j = 0; j < num; j++) {
				cin >> right;
				a[left][right] = 1;
			}
		}
		for (i = 0; i < n; i++) {
			memset(v, 0, sizeof(v));
			if (link[i] == INF && find(i)) {
				sum++;
				used[i] = 1;		//该点主动匹配了
			}
		}
		cout << n - sum << endl;
	}
	system("pause");
	return 0;
}