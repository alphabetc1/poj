#include <iostream>
#include <string.h>
#define NMAX 210
#define MAX(a, b) (a>b)?(a):(b)
using namespace std;

int maxLen[NMAX][NMAX];

int main()
{
	int i, j, aLen, bLen, leftMax, rightMax;
	char str1[210], str2[210];
	while (cin >> str1+1 >> str2+1)
	{
		memset(maxLen, 0, sizeof(maxLen));
		aLen = strlen(str1+1);
		bLen = strlen(str2+1);
		for(i = 1; i <= aLen; i++)
			for (j = 1; j <= bLen; j++)
			{
				if (str1[i] == str2[j])
				{
					maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
				}
				else
				{
					leftMax = maxLen[i - 1][j];
					rightMax = maxLen[i][j - 1];
					maxLen[i][j] = MAX(leftMax, rightMax);
				}
			}
		cout << maxLen[aLen][bLen] << endl;
	}
	return 0;
}
