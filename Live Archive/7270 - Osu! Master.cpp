/*
 * 7270 - Osu! Master.cpp
 *
 *  Created on: Sep 24, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	while (scanf("%d", &n) != EOF) {
		char s[2];
		int cnt, ans = 0;
		while (n--) {
			scanf("%s", s);
			if (s[0] == 'S')
				ans++;
			else {
				scanf("%d", &cnt);
				ans += cnt == 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
