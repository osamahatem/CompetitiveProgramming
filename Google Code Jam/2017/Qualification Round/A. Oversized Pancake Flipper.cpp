/*
 * A. Oversized Pancake Flipper.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char s[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T, k;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		scanf("%s%d", s, &k);
		int ans = 0;
		for (int i = 0; s[i + k - 1]; i++) {
			if (s[i] == '-') {
				ans++;
				for (int j = 0; j < k; j++)
					s[i + j] = (s[i + j] == '+' ? '-' : '+');
			}
		}
		for (int i = 0; s[i]; i++)
			if (s[i] == '-')
				ans = -1;
		if (ans == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
