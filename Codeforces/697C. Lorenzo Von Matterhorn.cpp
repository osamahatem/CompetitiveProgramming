/*
 * 697C. Lorenzo Von Matterhorn.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<pair<long long, long long>, long long> cost;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int q;
	scanf("%d", &q);
	while (q--) {
		int t;
		long long v, u;
		scanf("%d%lld%lld", &t, &u, &v);
		if (t == 2) {
			long long ans = 0;
			while (v != u) {
				if (v > u) {
					ans += cost[make_pair(v / 2, v)];
					v /= 2;
				} else {
					ans += cost[make_pair(u / 2, u)];
					u /= 2;
				}
			}
			printf("%lld\n", ans);
		} else {
			long long w;
			scanf("%lld", &w);
			while (v != u) {
				if (v > u) {
					cost[make_pair(v / 2, v)] += w;
					v /= 2;
				} else {
					cost[make_pair(u / 2, u)] += w;
					u /= 2;
				}
			}
		}
	}
	return 0;
}
