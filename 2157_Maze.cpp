/*暴力bfs，原则是如果找到钥匙/开到门就重新bfs
noi对应题号1159*/
#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#define NMAX 1010
#define GAP 6
#define MAX(a,b) (a>b)?(a):(b)
using namespace std;

int m, n, need[GAP], v[NMAX][NMAX];
int fw[4][2] = { {0,1},{0, -1},{1, 0},{-1, 0} };
char map[NMAX][NMAX];

int canPush(int sm, int sn) {
	if (sm >= 0 && sm < m && sn >= 0 && sn < n && !v[sm][sn] && map[sm][sn] != 'X')	return 1;
	else return 0;
}

int bfs(int sm, int sn) {
	int topm, topn, newm, newn, flag = 1;
	queue<int>q;
	while (flag) {
		flag = 0;
		memset(v, 0, sizeof(v));
		q.push(sm), q.push(sn);
		while (!q.empty()) {
			topm = q.front(), q.pop();
			topn = q.front(), q.pop();
			v[topm][topn] = 1;
			if (map[topm][topn] == 'G') {
				return 1;
			}
			else if (map[topm][topn] <= 'e' && map[topm][topn] >= 'a') {
				need[map[topm][topn] - 'a']--;
				map[topm][topn] = '.';
				if(!need[map[topm][topn] - 'a']) flag = 1;
			}
			for (int i = 0; i < 4; i++) {
				newm = topm + fw[i][0];
				newn = topn + fw[i][1];
				if (canPush(newm, newn)) {
					if (map[newm][newn] <= 'E' && map[newm][newn] >= 'A') {
						if (!need[map[newm][newn] - 'A']) {
							map[newm][newn] = '.';
							q.push(newm), q.push(newn);
						}
					}
					else {
						q.push(newm), q.push(newn);
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	int sm, sn;
	while (cin >> m >> n && m) {
		memset(need, 0, sizeof(need));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'S') {
					sm = i, sn = j;
				}
				else if (map[i][j] >= 'a' && map[i][j] <= 'e') {
					need[map[i][j] - 'a']++;
				}
			}
		}
		if (bfs(sm, sn))	cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	system("pause");
	return 0;
}