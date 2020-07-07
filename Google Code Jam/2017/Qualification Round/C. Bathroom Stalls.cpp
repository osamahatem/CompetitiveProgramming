/*
 * C. Bathroom Stalls.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		set<long long> S;
		map<long long, long long> mp;
		long long n, k, last;
		scanf("%lld%lld", &n, &k);
		S.insert(n);
		mp[n] = 1;
		while (k > 0) {
			last = *(--S.end());
			S.erase(last);
			k -= mp[last];
			S.insert(last / 2), mp[last / 2] += mp[last];
			S.insert((last - 1) / 2), mp[(last - 1) / 2] += mp[last];
		}
		printf("Case #%d: %lld %lld\n", t, last / 2, (last - 1) / 2);
	}

	return 0;
}
