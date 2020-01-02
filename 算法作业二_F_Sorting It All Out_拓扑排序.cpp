/*给定一些大小关系
**确定是否有唯一拓扑排序，以及是否产生冲突*/
#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#define NMAX 30
using namespace std;

struct node {
	int num, list[NMAX];				
}out[NMAX];

int n, m, in[NMAX], tmpIn[NMAX];
char str[5], seq[NMAX];
queue<int>q;

void getList() {
	cin >> str;
	int s = str[0] - 'A', t = str[2] - 'A';
	in[t]++;
	out[s].list[out[s].num] = t;
	out[s].num++;	
}

int topoSort() {
	while (!q.empty())	q.pop();
	for (int i = 0; i < n; i++) {
		if (!in[i])	q.push(i);
	}
	int num = 0, unsure = 0;
	memset(seq, 0, sizeof(seq));
	while (!q.empty()) {
		if (q.size() > 1)	unsure = 1;	//队列元素大于1，则必定不存在唯一拓扑排序
		int top = q.front();			//这里用unsure标记而不是直接返回0，因为出错返回的优先级更高
		q.pop();
		seq[num++] = top + 'A';
		for (int j = 0; j < out[top].num; j++) {
			int tmp = out[top].list[j];
			tmpIn[tmp]--;	
			if (!tmpIn[tmp]) {
				q.push(tmp);
			}
		}
	}
	if (num < n)	return 2;			//出现冲突，优先级高于不确定序列
	else if (unsure)	return 0;		//不确定序列
	else return 1;						//确定序列
}

int main() {
	int i, j, k, flag, getAns, ans;
	while (cin >> n >> m && n) {
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		getAns = false;
		flag = 0;
		for (i = 1; i <= m; i++) {
			getList();
			if (getAns)	continue;		//得到结果后继续读取数据
			flag = 0;
			memcpy(tmpIn, in, sizeof(in));
			flag = topoSort();
			if (flag) {
				ans = i;
				getAns = true;
			}
		}
		if (2 == flag) {
			cout << "Inconsistency found after " << ans << " relations." << endl;
		}
		else if (!flag) {
			cout << "Sorted sequence cannot be determined." << endl;
		}
		else {
			cout << "Sorted sequence determined after " << ans << " relations: " << seq << "." << endl;
		}
	}
	system("pause");
	return 0;
}
