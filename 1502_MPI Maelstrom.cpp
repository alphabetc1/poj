//dijkstra算法求单源最短路
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
#define INF 0x3f3f3f3f
#define MAX(a,b) (a>b)?(a):(b)
using namespace std;

int n, a[NMAX][NMAX], d[NMAX], v[NMAX];

int dijkstra() {
	int i, j, ans = 0;
	for (i = 1; i <= n; i++)
		d[i] = a[1][i];
	for (i = 0; i < n - 1; i++) {
		int x, minn = INF;
		for (j = 2; j <= n; j++) {
			if (!v[j] && d[j] < minn) {
				x = j;
				minn = d[j];
			}
		}
		v[x] = 1;
		ans = MAX(ans, minn);
		for (j = 2; j <= n; j++) {
			if (d[x] + a[x][j] < d[j]) {
				d[j] = d[x] + a[x][j];
			}
		}
	}
	return ans;
}

int main() {
	cin >> n;
	char str[NMAX];
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++) {
		a[i][i] = 0;
		for (int j = 1; j < i; j++) {
			cin >> str;
			if (str[0] != 'x') {
				a[i][j] = a[j][i] = atoi(str);
			}
		}
	}
	cout << dijkstra() << endl;
	system("pause");
	return 0;
}