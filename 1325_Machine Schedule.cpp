//匈牙利算法最小点覆盖
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
using namespace std;

int n, m, v[NMAX], link[NMAX], a[NMAX][NMAX];

int find(int x) {
	for (int i = 1; i <= m; i++) {
		if (!v[i] && a[x][i]) {
			v[i] = 1;
			if (!link[i] || find(link[i])) {
				link[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int i, j, k, sum, mid, left, right;
	while (cin >> n && n) {
		sum = 0;
		memset(link, 0, sizeof(link));
		memset(a, 0, sizeof(a));
		cin >> m >> k;
		for (i = 0; i < k; i++) {
			cin >> mid >> left >> right;
			a[left][right] = 1;
		}
		for (i = 1; i <= n; i++) {
			memset(v, 0, sizeof(v));
			if (find(i))
				sum++;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}