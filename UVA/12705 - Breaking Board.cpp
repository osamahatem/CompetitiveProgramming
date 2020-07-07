/*
 * 12705 - Breaking Board.cpp
 *
 *  Created on: Aug 9, 2014
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

	int cost[40], t;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			cost[i * 6 + j] = i + j + 2;
	sort(cost, cost + 36);
	scanf("%d ", &t);
	while (t--) {
		int cnt[40];
		memset(cnt, 0, sizeof cnt);
		string s;
		getline(cin, s);
		for (int i = 0; i < (int) s.size(); i++)
			if (isalpha(s[i]))
				cnt[s[i] - 'A']++;
			else if (s[i] >= '0' && s[i] <= '9')
				cnt[s[i] - '0' + 26]++;
		sort(cnt, cnt + 40, greater<int>());
		int ans = 0;
		for (int i = 0; i < 36; i++)
			ans += cnt[i] * cost[i];
		printf("%d\n", ans);
	}
	return 0;
}
