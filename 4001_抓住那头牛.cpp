#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#define NMAX 100010
using namespace std;

int v[NMAX];

int canPush(int x) {
	if (x >= 0 && x <= 100000 && !v[x])	return 1;
	else return 0;
}

int bfs(int st, int ed) {
	int top, cost;
	queue<int>q;
	q.push(st), q.push(0);
	while (!q.empty()) {
		top = q.front(), q.pop();
		cost = q.front(), q.pop();
		v[top] = 1;
		if (top == ed) {
			return cost;
		}
		else {
			if (canPush(top - 1)) {
				q.push(top - 1), q.push(cost + 1);
			}
			if (canPush(top + 1)) {
				q.push(top + 1), q.push(cost + 1);
			}
			if (canPush(2 * top)) {
				q.push(2 * top), q.push(cost + 1);
			}
		}
	}
}

int main() {
	int st, ed;
	cin >> st >> ed;
	cout << bfs(st, ed) << endl;
	system("pause");
	return 0;
}