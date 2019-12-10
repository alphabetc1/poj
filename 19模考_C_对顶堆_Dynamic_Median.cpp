/*���һ�����ݽṹ����ʼΪ�գ�֧�����²�����
��1������һ��Ԫ�أ�Ҫ����log(n)ʱ������ɣ�����n�Ǹ����ݽṹ�е�ǰԪ�صĸ�����ע�⣺���ݽṹ���������ظ���Ԫ�ء�
��2�����ص�ǰԪ�ؼ��ϵ���λ����Ҫ���ڳ���ʱ������ɡ������ǰԪ�صĸ���Ϊż������ô��������λ������������λ���н�С��һ������
��3��ɾ����λ����Ҫ����log(n)ʱ������ɡ�
���öԶ���(��С��+���ѣ��߶Ȳ����1)����λ��Ϊ��С�ѶѶ�*/
#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
#include <functional>
#define NMAX 10010
using namespace std;

int main() {
	char op;
	int i, j, t, n, num;
	scanf("%d", &t);
	while (t--) {
		priority_queue<int>q1;
		priority_queue<int, vector<int>, greater<int>>q2;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf(" %c",&op);
			switch (op) {
			case 'I':scanf(" %d", &num);
				if (!q1.size() || num < q1.top())
					q1.push(num);
				else q2.push(num);
				if (q2.size() > q1.size()) {
					num = q2.top(), q2.pop();
					q1.push(num);
				}
				if (q1.size() > q2.size() + 1) {
					num = q1.top(), q1.pop();
					q2.push(num);
				}
				break;
			case 'Q':printf("%d\n", q1.top());
				break;
			case 'D':q1.pop();
				if (q2.size() > q1.size()) {
					num = q2.top(), q2.pop();
					q1.push(num);
				}
				break;
			default:break;
			}
		}
	}
	system("pause");
	return 0;
}