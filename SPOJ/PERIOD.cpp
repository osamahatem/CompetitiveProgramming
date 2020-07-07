/*
 * PERIOD.cpp
 *
 *  Created on: Jun 14, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char str[1000005];
int fail[1000005], ans[1000005], len;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%*d%s", str);
		printf("Test case #%d\n", t);
		fail[0] = 0, len = 0;
		for (int i = 1; str[i]; i++) {
			while (len && str[i] != str[len])
				len = fail[len - 1];
			if (str[len] == str[i])
				len++;
			fail[i] = len;
		}
		for (int i = 0; str[i]; i++) {
			if (fail[i] && i - fail[i] + 1 == fail[i] / ans[fail[i] - 1])
				ans[i] = ans[fail[i] - 1] + 1;
			else
				ans[i] = 1;
			if (ans[i] > 1)
				printf("%d %d\n", i + 1, ans[i]);
		}
		printf("\n");
	}
	return 0;
}
