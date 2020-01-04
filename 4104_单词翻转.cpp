#include <iostream>
#include <string>
#include <string.h>
#define NMAX 510
using namespace std;

int main() {
	int i, j, k;
	char c, str[NMAX];
	fgets(str, NMAX, stdin);
	int len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] != ' ') {
			for (j = i+1; j < len && str[j] != ' ' && str[j] != '\n'; j++);
			for (k = 0; k < (j - i) / 2; k++) {
				c = str[i + k];
				str[i + k] = str[j - 1 - k];
				str[j - 1 - k] = c;
			}
			i = j;
		}
	}
	cout << str;
	system("pause");
	return 0;
}