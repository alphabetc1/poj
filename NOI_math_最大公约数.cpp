#include <stdio.h>
#include <string>
#define max(a,b) (a>=b?a:b)
#define min(a,b) (a>=b?b:a)
int main()
{
	int m, n,a,b;
	while (scanf("%d%d", &m, &n) != EOF) {
		a = max(m, n);
		b = min(m, n);
		while (a % b != 0)
		{
			m = a % b;
			n = b;
			a = max(m, n);
			b = min(m, n);
		}
		printf("%d\n", b);
	}
	system("pause");
	return 0;
}