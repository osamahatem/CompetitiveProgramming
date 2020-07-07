/*
 * SNAKPROC.cpp
 *
 *  Created on: May 20, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char str[505];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int len = 0;
		scanf("%*d%s", str);
		for (int i = 0; str[i]; i++)
			if (str[i] != '.')
				str[len++] = str[i];
		bool flag = (len & 1) || (str[0] == 'T');
		for (int i = 1; i < len; i++)
			if (str[i] == str[i - 1])
				flag = 1;
		printf("%s\n", flag ? "Invalid" : "Valid");
	}
	return 0;
}
