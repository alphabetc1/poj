#include <iostream>
#include <string>
#include <string.h>
#define NMAX 110
using namespace std;

struct node {
	int num, left, right;
}newNode, tree[NMAX];

int main() {
	int i, j, t, n, m, tag, left, right, tmp, pos1, pos2;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(tree, 0, sizeof(tree));
		for (i = 0; i < n; i++) {
			cin >> tag >> left >> right;
			tree[tag].num = tag;
			tree[tag].left = left;
			tree[tag].right = right;
		}
		for (i = 0; i < m; i++) {
			cin >> tag;
			if (tag == 2) {
				cin >> tmp;
				for (j = 0; j < n && tree[j].num != tmp; j++);
				while (tree[j].left != -1 && tree[j].left != 0)	j = tree[j].left;
				cout << tree[j].num << endl;
			}
			else {
				cin >> tmp;
				for (j = 0; j < n && tree[j].num != tmp; j++);
				pos1 = j;
				cin >> tmp;
				for (j = 0; j < n && tree[j].num != tmp; j++);
				pos2 = j;
				newNode = tree[pos2];
				tree[pos2] = tree[pos1];
				tree[pos1] = newNode;
			}
		}
	}
	system("pause");
	return 0;
}