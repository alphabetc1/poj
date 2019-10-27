#include <stdio.h>
#include <string>
int main()
{
	int i, n, na, nb, count,  a[110], b[110];
	count = 0;
	scanf("%d %d %d", &n, &na, &nb);
	for (i = 0; i < na; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < nb; i++)
		scanf("%d", &b[i]);
	for (i = 0; i < n; i++)
	{
		if (a[i%na] == 0 && b[i%nb] == 2)	count++;
		else if (a[i%na] == 2 && b[i%nb] == 5)	count++;
		else if (a[i%na] == 5 && b[i%nb] == 0)	count++;
		else if (a[i%na] == b[i%nb]);
		else count--;
	}
	if (count > 0)	printf("A");
	else if (count < 0)	printf("B");
	else printf("draw");
	return 0;
}