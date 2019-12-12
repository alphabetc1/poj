//归并排序+统计逆序数
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 500010
#define MAX(a,b) (a>b)?(a):(b)
using namespace std;

int n, a[NMAX], b[NMAX];
long long sum;

void merge(int st, int mid, int ed) {
	int i = st, j = mid, k = st, t = 0;
	memcpy(b + st, a + st, (ed - st) * sizeof(int));
	while (i < mid && j < ed) {
		if (b[i] > b[j]) {
			a[k++] = b[j];
			sum += mid - i;
			t++;
			j++;
		}
		else {
			a[k++] = b[i];
			i++;
		}
	}
	while (i < mid) {
		a[k++] = b[i++];
	}
	while (j < ed) {
		a[k++] = b[j++];
	}
}

void mergeSort(int st, int ed) {
	if (st == ed - 1)	return;
	int mid = (st + ed) / 2;
	mergeSort(st, mid);
	mergeSort(mid, ed);
	merge(st, mid, ed);
}

int main() {
	int i, j;
	while (cin >> n && n) {
		sum = 0;
		for (i = 0; i < n; i++)
			cin >> a[i];
		mergeSort(0, n);
		cout << sum << endl;
	}
	system("pause");
	return 0;
}