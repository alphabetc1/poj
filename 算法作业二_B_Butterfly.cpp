/*因为只有2种物种，假设a为物种1，则a+n设为物种2(可以理解为a+n为a的反类)
如果物种a，b不同，则a与b+n相同，a+n与b相同
所以数组需要2*NMAX大小，为了容纳反类*/
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 1010
using namespace std;

int n, m, fa[2 * NMAX];		//2倍NMAX以容纳反类

void init() {
	for (int i = 1; i <= 2 * n; i++)	//2倍NMAX以容纳反类
		fa[i] = i;
}

int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

int same(int x, int y) {
	return find(x) == find(y);		//主要要用find(x)而不是fa[x]
}

void join(int x, int y) {
	if (!same(x, y))
		fa[x] = y;
}

//void join(int x, int y) {			不用same()的写法	
//	x = find(x), y = find(y);		注意要是find(x)而不是fa[x]
//	if (x != y)
//		fa[y] = x;
//}

int main() {
	int i, j, a, b, tag, flag;
	while (cin >> n >> m) {
		flag = 0;
		init();
		for (i = 0; i < m; i++) {
			cin >> a >> b >> tag;
			if (tag) {
				if (same(a, b))	
					flag = 1;
				else{
					join(a, b + n);
					join(a + n, b);
				}
			}
			else {
				if (same(a, b + n) || same(a + n, b))	
					flag = 1;
				else {
					join(a, b);
					join(a + n, b + n);
				}
			}
		}
		if (flag)	cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	system("pause");
	return 0;
}