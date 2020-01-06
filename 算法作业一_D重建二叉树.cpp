#include <iostream>
#include <string>
#include <string.h>
#define NMAX 1010
using namespace std;

struct node {
	node *l, *r;
	char c;
};
char str1[NMAX], str2[NMAX];

node *getTree(int s1, int e1, int s2, int e2) {
	if (s1 > e1 || s2 > e2)	return NULL;
	int i;
	for (i = s2; str2[i] != str1[s1]; i++);
	node *subTree = (node*)malloc(sizeof(node));
	subTree->c = str1[s1];
	subTree->l = getTree(s1+1, s1 + i - s2, s2, i-1);
	subTree->r = getTree(s1 + i - s2 + 1 , e1, i+1, e2);
	return subTree;
}

void printOrder(node *p) {
	if (p) {
		printOrder(p->l);
		printOrder(p->r);
		cout << p->c;
	}
}

int main() {
	while (cin >> str1 >> str2) {
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		node *root;
		root = getTree(0, len1 - 1, 0, len2 - 1);
		printOrder(root);
		cout << endl;
	}
	system("pause");
	return 0;
}
