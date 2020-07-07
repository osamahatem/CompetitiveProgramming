/*
 * 853A. Planning.cpp
 *
 *  Created on: Sep 11, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k;
vector<pair<int, int>> all;
set<int> idx;
int out[300005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int c;
		scanf("%d", &c);
		all.push_back( { c, i });
		idx.insert(k + i);
	}
	sort(all.rbegin(), all.rend());
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		auto it = idx.lower_bound(all[i].second);
		ans += 1ll * all[i].first * (*it - all[i].second);
		out[all[i].second] = *it + 1;
		idx.erase(it);
	}
	printf("%lld\n", ans);
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%d", out[i]);
	}
	printf("\n");
	return 0;
}
