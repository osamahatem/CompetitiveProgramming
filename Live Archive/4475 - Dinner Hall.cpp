/*
 * 4475 - Dinner Hall.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

#define mp make_pair

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int N;
	while (scanf("%d", &N), N) {
		vector<pair<int, char>> all;
		int entry = 0;
		for (int i = 0; i < N; i++) {
			int h, m, s;
			char c;
			scanf("%d:%d:%d%*c%c", &h, &m, &s, &c);
			int timer = s + 60 * m + 3600 * h;
			all.push_back(mp(timer, c));
			if (c == 'E')
				entry++;
		}
		sort(all.begin(), all.end());
		int rem = N / 2 - entry, pple = 0, res = 0;
		for (int i = 0; i < N; i++) {
			if (all[i].second == 'E')
				pple++;
			else if (all[i].second == 'X')
				pple--;
			else {
				if (rem)
					pple++, rem--;
				else
					pple--;
			}
			res = max(res, pple);
		}
		printf("%d\n", res);
	}
	return 0;
}
