#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
#define INF 0x3f3f3f3f
#define MIN(a,b) (a<b)?(a):(b)
using namespace std;

int a[NMAX], sum[NMAX], value[NMAX][NMAX];

int main() {
	int n, i, j, h, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}
	for (h = 1; h < n; h++) {
		for (i = 1, j = i + h; j <= n; i++, j++) {
			value[i][j] = INF;
			for (k = i; k < j; k++) {
				value[i][j] = MIN(value[i][j], value[i][k] + value[k+1][j] + sum[j] - sum[i-1]);
			}
		}
	}
	cout << value[1][n] << endl;
	system("pause");
	return 0;
}
