/*
 * 7001 - Bus Problem.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct DisjointSet {
	vector<int> rnk, id;

	DisjointSet(int n) {
		for (int i = 0; i <= n; i++)
			rnk.push_back(1), id.push_back(i);
	}

	int find(int x) {
		if (x == id[x])
			return x;
		return id[x] = find(id[x]);
	}

	bool merge(int a, int b) {
		int fa = find(a), fb = find(b);
		if (fa == fb)
			return false;
		if (rnk[a] > rnk[b])
			swap(a, b);
		id[fa] = fb;
		return true;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int c, r, a, b, d;
		scanf("%d%d", &c, &r);
		vector<pair<int, pair<int, int>>> all;
		while (r--) {
			scanf("%d%d%d", &a, &b, &d);
			all.push_back(make_pair(d, make_pair(a, b)));
		}
		sort(all.begin(), all.end());
		DisjointSet DS(c);
		int ans = 0;
		for (int i = 0; i < (int) all.size(); i++)
			if (!DS.merge(all[i].second.first, all[i].second.second))
				ans += all[i].first;
		printf("%d\n", ans);
	}
	return 0;
}
