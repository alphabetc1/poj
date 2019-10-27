#include <stdio.h>
#include <string>
void hanoi(int, char, char, char);
int main()
{
	int n;
	char a, b, c;
	scanf("%d %c %c %c", &n, &a, &b, &c);
	hanoi(n, a, b, c);
	system("pause");
	return 0;
}

void hanoi(int n, char a, char b, char c)
{
	if (n == 0)	return;
	hanoi(n - 1, a, c, b);
	printf("%d:%c->%c\n", n, a, c);
	hanoi(n - 1, b, a, c);
}