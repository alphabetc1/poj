/*设计一个数据结构，初始为空，支持以下操作：
（1）增加一个元素，要求在log(n)时间内完成，其中n是该数据结构中当前元素的个数。注意：数据结构中允许有重复的元素。
（2）返回当前元素集合的中位数，要求在常数时间内完成。如果当前元素的个数为偶数，那么返回下中位数（即两个中位数中较小的一个）。
（3）删除中位数，要求在log(n)时间内完成。
采用对顶堆(最小堆+最大堆，高度差不超过1)，中位数为最小堆堆顶*/
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