/*
 * 12707 - Block Meh.cpp
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

	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int n, a, b;
		vector<pair<int, int> > all;
		scanf("%d", &n);
		while (n--) {
			scanf("%d%d", &a, &b);
			all.push_back(make_pair(a, b));
		}
		sort(all.begin(), all.end());
		int ans = 0;
		multiset<int> E;
		multiset<int>::iterator it;
		for (int i = 0; i < (int) all.size(); i++) {
			it = E.lower_bound(all[i].second + 1);
			if (it == E.end())
				ans++;
			else
				E.erase(it);
			E.insert(all[i].second);
		}
		printf("Case %d: %d\n", tc, ans);
	}
	return 0;
}
