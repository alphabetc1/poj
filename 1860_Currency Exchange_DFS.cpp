/*可以用bellman-ford/dfs做
**dfs简单点*/
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
#define MAX(a,b) (a>b)?(a):(b)
using namespace std;

int n, m, flag, v[NMAX];
double money[NMAX], r[NMAX][NMAX], c[NMAX][NMAX];

void dfs(int s) {
	for (int i = 1; i <= n; i++) {
		if (!r[s][i])	continue;
		if (!v[i]) {
			v[i] = 1;
			money[i] = MAX(money[i], (money[s] - c[s][i]) * r[s][i]);
			dfs(i);
			v[i] = 0;
		}
		else {
			if ((money[s] - c[s][i]) * r[s][i] > money[i])	flag = 0;
		}
	}
}

int main() {
	int i, j, s, x, y;
	double now;
	cin >> n >> m >> s >> now;
	money[s] = now;
	for (i = 0; i < m; i++) {
		cin >> x >> y;
		cin >> r[x][y] >> c[x][y] >> r[y][x] >> c[y][x];
	}
	v[s] = flag = 1;
	dfs(s);
	if (flag) {
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;
	system("pause");
	return 0;
}