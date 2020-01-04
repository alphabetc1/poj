#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
#define MAX(a,b) (a>b)?(a):(b)
using namespace std;

int a[NMAX], up[NMAX], down[NMAX];

int main() {
	int i, j, k, n;
	cin >> k;
	while (k--) {
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i];
			up[i] = down[i] = 1;
		}
		for (i = 1; i < n; i++) {
			for (j = 0; j < i; j++) {
				if (a[i] > a[j]) {
					up[i] = MAX(up[i], up[j] + 1);
				}
				else if (a[i] < a[j]) {
					down[i] = MAX(down[i], down[j] + 1);
				}
			}
		}
		int ans = 1;
		for (i = 0; i < n; i++) {
			ans = MAX(ans, up[i]);
			ans = MAX(ans, down[i]);
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}