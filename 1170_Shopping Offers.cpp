<<<<<<< HEAD
//5Î¬dp£¬Èç¹ûÓÃ×´Ì¬Ñ¹Ëõ´úÂë»áÓÅÑÅºÜ¶àorz
=======
//5ç»´dpï¼Œå¦‚æžœç”¨çŠ¶æ€åŽ‹ç¼©ä»£ç ä¼šä¼˜é›…å¾ˆå¤šorz
>>>>>>> 1831913e3b9f19810afd67ddca75e63ed88f1d14
#include <iostream>
#include <string>
#include <string.h>
#define NMAX 1010
#define gap 7
#define MIN(a,b) (a<b)?(a):(b)
using namespace std;

struct node {
	int cost, num[gap];
}item[NMAX];

int need[gap], tag[NMAX], dp[gap][gap][gap][gap][gap];

int main() {
	int i, j, s, n, m, num, v[gap];
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> num;
		tag[num] = i;
		cin >> need[i] >> item[i].cost;	
		item[i].num[i] = 1;
	}
	cin >> s;
	for (i = n; i < n + s; i++) {
		cin >> m;
		for (j = 0; j < m; j++) {
			cin >> num;
			cin >> item[i].num[tag[num]];
		}
		cin >> item[i].cost;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0][0][0] = 0;
	for (i = 0; i < n + s; i++)
		for (v[0] = item[i].num[0]; v[0] <= need[0]; v[0]++)
			for (v[1] = item[i].num[1]; v[1] <= need[1]; v[1]++)
				for (v[2] = item[i].num[2]; v[2] <= need[2]; v[2]++)
					for (v[3] = item[i].num[3]; v[3] <= need[3]; v[3]++)
						for (v[4] = item[i].num[4]; v[4] <= need[4]; v[4]++) {
							dp[v[0]][v[1]][v[2]][v[3]][v[4]] = MIN(dp[v[0]][v[1]][v[2]][v[3]][v[4]], dp[v[0] - item[i].num[0]][v[1] - item[i].num[1]][v[2] - item[i].num[2]][v[3] - item[i].num[3]][v[4] - item[i].num[4]] + item[i].cost);
						}
	cout << dp[need[0]][need[1]][need[2]][need[3]][need[4]] << endl;
	system("pause");
	return 0;
}
