/*
 * D. Laying Cables.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int x, p, id, ans;

	static const bool byP(const node &a, const node &b) {
		return a.p > b.p;
	}

	static const bool byID(const node &a, const node &b) {
		return a.id < b.id;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	vector<node> all(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &all[i].x, &all[i].p);
		all[i].id = i;
	}
	sort(all.begin(), all.end(), node::byP);
	all[0].ans = -1;
	set<pair<int, pair<int, int>>> big;
	big.insert(make_pair(all[0].x, make_pair(all[0].id, all[0].p)));
	for (int i = 1; i < n; i++) {
		auto it = big.lower_bound(make_pair(all[i].x, make_pair(0, 0)));
		all[i].ans = -1;
		int diff = 1 << 30, p = 1 << 30;
		if (it != big.end()) {
			all[i].ans = it->second.first + 1;
			diff = it->first - all[i].x, p = it->second.second;
		}
		if (it != big.begin()) {
			it--;
			int tempDiff = all[i].x - it->first;
			if (tempDiff < diff || (tempDiff == diff && it->second.second > p))
				all[i].ans = it->second.first + 1;
		}
		big.insert(make_pair(all[i].x, make_pair(all[i].id, all[i].p)));
	}
	sort(all.begin(), all.end(), node::byID);
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%d", all[i].ans);
	}
	return 0;
}
