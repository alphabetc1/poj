//匈牙利算法模板题
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 310
using namespace std;

int p, n, v[NMAX], link[NMAX], a[NMAX][NMAX];

int find(int x) {
	for (int i = 1; i <= n; i++) {
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
	int t, i, j, tmp, num, sum;
	cin >> t;
	while (t--) {
		sum = 0;
		cin >> p >> n;
		memset(a, 0, sizeof(a));
		memset(link, 0, sizeof(link));
		for (i = 1; i <= p; i++) {
			cin >> num;
			for (j = 1; j <= num; j++) {
				cin >> tmp;
				a[i][tmp] = 1;
			}
		}
		for (i = 1; i <= p; i++) {
			memset(v, 0, sizeof(v));
			if (find(i))
				sum++;
		}
		if (sum == p)	cout << "YES" << endl;
		else cout << "NO" << endl;
	}


	system("pause");
	return 0;
}