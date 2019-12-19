#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
using namespace std;

int n = 1, a[NMAX], b[NMAX];

void findPath(int starta, int enda, int startb, int endb) {
	int i;
	if (starta > enda)
		return;
	cout << b[endb] << " ";
	for (i = starta; i <= enda && a[i] != b[endb]; i++);
	findPath(starta, i - 1, startb, startb + i - 1 - starta);
	findPath(i + 1, enda, startb + i - starta, endb - 1);
}

int main() {
	while (cin >> a[n]) {
		n++;
	}
	n /= 2;
	for (int i = 1; i <= n; i++) {
		b[i] = a[n + i];
	}
	findPath(1, n, 1, n);
	system("pause");
	return 0;
}