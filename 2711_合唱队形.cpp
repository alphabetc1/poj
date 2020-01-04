//π…∆±¬Ú¬Ù±‰÷÷
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
#define MAX(a,b) (a>b)?(a):(b)
using namespace std;

int a[NMAX], up[NMAX], down[NMAX];

int main() {
	int i, j, n, max = 0;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		up[i] = down[i] = 1;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j < i; j++) {
			if (a[i] > a[j]) {
				up[i] = MAX(up[i], up[j] + 1);
			}
		}
	}
	for (i = n; i >= 1; i--) {
		for (j = i+1; j <= n; j++) {
			if (a[i] > a[j]) {
				down[i] = MAX(down[i], down[j] + 1);
			}
		}
	}
	for (i = n - 1; i >= 1; i--) {
		down[i] = MAX(down[i], down[i + 1]);
	}
	for (i = 1; i <= n; i++) {
		max = MAX(max, up[i - 1] + down[i]);
	}
	cout << n - max << endl;
	system("pause");
	return 0;
}