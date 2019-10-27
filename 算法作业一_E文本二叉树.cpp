#include <stdio.h>
#include <string>
#include <string.h>

int num;
char c[110];
struct node
{
	char c;
	node *l, *r;
};

void preOrder(node *a)
{
	if (a->l)	preOrder(a->l);
	if (a->c != '*')	printf("%c", a->c);
	if (a->r)	preOrder(a->r);
}
void inOrder(node *a)
{
	if (a->c != '*')	printf("%c", a->c);
	if (a->l)	inOrder(a->l);
	if (a->r)	inOrder(a->r);
}
void outOrder(node *a)
{
	if (a->l)	outOrder(a->l);
	if (a->r)	outOrder(a->r);
	if (a->c != '*')	printf("%c", a->c);
}

node *tree(node *a, int k)
{
	if (c[0] == '0')	return a;
	num = strlen(c) - 1;
	if (num < k )	return a;
	else if (num == k && a == NULL)
	{
		a = new node;
		a->c = c[num];
		a->l = a->r = NULL;
		scanf("%s", c);
		a->l = tree(a->l, k + 1);
	}
	if (num == k && a)	return a;
	if (num > k)
	{
		a->r = tree(a->r, k + 1);
	}
	return a;
}

int main()
{
	int i, n;
	scanf("%d", &n);
	while (n--)
	{
		node *root = NULL;
		scanf("%s", &c);
		root = tree(root, 0);
		inOrder(root);
		printf("\n");
		outOrder(root);
		printf("\n");
		preOrder(root);
		printf("\n\n");
	}
	system("pause");
	return 0;
}