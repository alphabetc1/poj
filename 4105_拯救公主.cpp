/*v[i][j][stat]������㵽��ij����С����
**statΪԿ��״̬��������11011(27)��ʾ�Ѿ�ӵ��0��1��3��4��Կ��
**��Ҫk��Կ�ף���ֻ�����v[i][j][(1<<k)-1]*/
#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#define INF 0x3f3f3f3f
#define NMAX 210
using namespace std;

struct node {
	int n, m;
}gate[12];						//������

int n, m, gateNum, v[NMAX][NMAX][1 << 5];
int fw[4][2] = { {0,1}, {0,-1} ,{1,0}, {-1,0} };
char map[NMAX][NMAX];

void bfs(int sn, int sm, int need) {
	queue<int>q;
	int tn, tm, tstat;
	q.push(sn), q.push(sm), q.push(0);
	v[sn][sm][0] = 0;
	while (!q.empty()) {
		tn = q.front(), q.pop();
		tm = q.front(), q.pop();
		tstat = q.front(), q.pop();
		int num = v[tn][tm][tstat] + 1;
		for (int i = 0; i < 4; i++) {
			int nn, nm, nstat;
			nn = tn + fw[i][0], nm = tm + fw[i][1], nstat = tstat;
			if (nn < 0 || nn >= n || nm < 0 || nm >= m || map[nn][nm] == '#')  continue;
			if (map[nn][nm] >= '0' && map[nn][nm] <= '4') {
				nstat |= 1 << (map[nn][nm] - '0');
			}
			if (num >= v[nn][nm][nstat])	continue;		//��ǰ·�Ѿ��߹�����Կ��״̬��δ�ı�
			if (map[nn][nm] == '$') {
				for (int i = 0; i < gateNum; i++) {
					v[gate[i].n][gate[i].m][nstat] = num;
					q.push(gate[i].n), q.push(gate[i].m), q.push(nstat);
				}
			}
			else {
				v[nn][nm][nstat] = num;
				if (map[nn][nm] == 'E' && nstat == (1 << need) - 1)	return;
				else {
					q.push(nn), q.push(nm), q.push(nstat);
				}
			}
		}
	}
}

int main() {
	int t, sn, sm, en, em, need;
	cin >> t;
	while (t--) {
		gateNum = 0;
		memset(v, 0x3f, sizeof(v));
		cin >> n >> m >> need;
		for(int i = 0; i < n; i++)	
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				if (map[i][j] == '$') {
					gate[gateNum].n = i;
					gate[gateNum].m = j;
					gateNum++;
				}
				else if (map[i][j] == 'S') {
					sn = i, sm = j;
				}
				else if (map[i][j] == 'E') {
					en = i, em = j;
				}
			}
		bfs(sn, sm, need);
		if (v[en][em][(1<<need)-1] == INF)	cout << "oop!" << endl;
		else cout << v[en][em][(1 << need) - 1] << endl;
	}
	system("pause");
	return 0;
}