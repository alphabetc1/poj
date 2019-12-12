#include <iostream>
#include <string>
#include <string.h>
#define NMAX 30010
using namespace std;

int n, m, fa[NMAX];

void fa_init() {
	for (int i = 0; i < n; i++)
		fa[i] = i;
}

int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

void join(int x, int y) {
	x = find(x), y = find(y);		//注意要是find(x)而不是fa[x]
	if (x != y)
		fa[y] = x;
}

int main() {
	int i, j, num, left, right, tmp, sum;
	while (cin >> n >> m && n) {
		fa_init();
		sum = 1;
		for (i = 0; i < m; i++) {
			cin >> num >> left;
			for (j = 0; j < num - 1; j++) {
				cin >> right;
				join(left, right);
			}
		}
		tmp = find(0);
		for (i = 1; i < n; i++) {
			if (find(i) == tmp)
				sum++;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}