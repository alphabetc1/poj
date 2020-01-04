/*股票买卖变种
**记得考虑全为负数的情况*/
#include <stdio.h>
#include <string>
#include <string.h>
#define NMAX 50010
#define MAX(a,b) (a>b)?(a):(b)

int a[NMAX], lt[NMAX], rt[NMAX];

int main() {
	int t, n, i, ans;
	//scanf("%d", &t);
	while (scanf("%d", &n) && n) {
		
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			lt[i] = rt[i] = a[i];
		}
		ans = a[1] + a[2];					//考虑全为负数的情况
		for (i = 2; i <= n; i++) {
			lt[i] = MAX(lt[i], lt[i] + lt[i - 1]);
		}
		for (i = n-1; i >= 1; i--) {
			rt[i] = MAX(rt[i], rt[i] + rt[i + 1]);
		}
		for (i = n - 1; i >= 1; i--)
			rt[i] = MAX(rt[i + 1], rt[i]);
		for (i = 2; i <= n; i++) {
			ans = MAX(ans, lt[i - 1] + rt[i]);
		}
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}