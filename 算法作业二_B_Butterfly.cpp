/*��Ϊֻ��2�����֣�����aΪ����1����a+n��Ϊ����2(�������Ϊa+nΪa�ķ���)
�������a��b��ͬ����a��b+n��ͬ��a+n��b��ͬ
����������Ҫ2*NMAX��С��Ϊ�����ɷ���*/
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 1010
using namespace std;

int n, m, fa[2 * NMAX];		//2��NMAX�����ɷ���

void init() {
	for (int i = 1; i <= 2 * n; i++)	//2��NMAX�����ɷ���
		fa[i] = i;
}

int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

int same(int x, int y) {
	return find(x) == find(y);		//��ҪҪ��find(x)������fa[x]
}

void join(int x, int y) {
	if (!same(x, y))
		fa[x] = y;
}

//void join(int x, int y) {			����same()��д��	
//	x = find(x), y = find(y);		ע��Ҫ��find(x)������fa[x]
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