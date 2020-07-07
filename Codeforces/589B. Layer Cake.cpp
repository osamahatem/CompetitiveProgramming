/*
 * 589B. Layer Cake.cpp
 *
 *  Created on: Oct 27, 2015
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

	int n, x = 0, y = 0;
	long long ans = 0;
	scanf("%d", &n);
	vector<pair<int, int>> all(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &all[i].first, &all[i].second);
		if (all[i].first < all[i].second)
			swap(all[i].first, all[i].second);
	}
	sort(all.begin(), all.end(), greater<pair<int, int>>());
	map<int, int> wCnt;
	for (int i = 0; i < n; i++) {
		wCnt[all[i].second]++;
		int curCnt = 0, mw = 0;
		long long temp = 0;
		for (auto it = wCnt.rbegin(); it != wCnt.rend(); it++) {
			curCnt += it->second;
			if (1ll * curCnt * all[i].first * it->first > temp)
				temp = 1ll * curCnt * all[i].first * it->first, mw = it->first;
		}
		if (temp > ans)
			ans = temp, x = all[i].first, y = mw;
	}
	printf("%I64d\n%d %d\n", ans, x, y);
	return 0;
}
