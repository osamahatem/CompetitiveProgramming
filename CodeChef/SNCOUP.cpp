/*
 * SNCOUP.cpp
 *
 *  Created on: May 31, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
char in[2][100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int ans = 0, cnt = 0;
		for (int i = 0; i < 2; i++) {
			scanf("%s", in[i]);
			for (int j = 0; j < n; j++)
				if (in[i][j] == '*') {
					cnt++;
					break;
				}
		}
		if (cnt == 2)
			ans++;
		bool r1 = 0, r2 = 0;
		for (int i = 0; i < n; i++) {
			if ((in[0][i] == '*' && r1) || (in[1][i] == '*' && r2)) {
				ans++;
				r1 = in[0][i] == '*';
				r2 = in[1][i] == '*';
			} else {
				r1 |= in[0][i] == '*';
				r2 |= in[1][i] == '*';
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
