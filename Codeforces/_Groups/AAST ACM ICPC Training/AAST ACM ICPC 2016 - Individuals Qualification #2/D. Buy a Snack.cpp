/*
 * D. Buy a Snack.cpp
 *
 *  Created on: Aug 31, 2016
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

//	freopen("buy.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, v;
		long long ans = -(1ll << 60);
		map<int, int> cnt;
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &v);
			cnt[v]++;
		}
		for (auto it = cnt.begin(); it != cnt.end(); it++)
			ans = max(ans, 1ll * it->first * it->second);
		printf("%lld\n", ans);
	}
	return 0;
}
