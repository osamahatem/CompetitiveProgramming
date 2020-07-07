/*
 * C. Canvas Painting.cpp
 *
 *  Created on: Oct 1, 2017
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
	while (t--) {
		int n;
		scanf("%d", &n);
		multiset<long long> all;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			all.insert(x);
		}
		long long ans = 0;
		while (all.size() > 1) {
			long long a = *all.begin();
			all.erase(all.begin());
			long long b = *all.begin();
			all.erase(all.begin());
			ans += a + b;
			all.insert(a + b);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
