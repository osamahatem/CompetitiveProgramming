/*
 * J. Box Hedge.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<int, pair<int, int>> lim;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, y;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &x, &y);
		if (lim.count(y)) {
			lim[y].first = min(lim[y].first, x - 1);
			lim[y].second = max(lim[y].second, x + 1);
		} else
			lim[y] = make_pair(x - 1, x + 1);
	}
	int last = lim.rbegin()->first;
	int mnx = lim[last].first, mxx = lim[last].second;
	long long c = mxx - mnx + 5, sz = mxx - mnx + 3, a = 0;
	for (auto it = lim.rbegin(); it != lim.rend(); it++) {
		y = it->first;
		if (lim[y].first < mnx)
			c += mnx - lim[y].first, sz += mnx - lim[y].first;
		if (lim[y].second > mxx)
			c += lim[y].second - mxx, sz += lim[y].second - mxx;
		c += (last - y) * 2;
		sz += (last - y) * 2;
		a += 1ll * (last - y) * (mxx - mnx - 1);
		last = y;
		mnx = min(mnx, lim[y].first);
		mxx = max(mxx, lim[y].second);
	}
	c += last * 2;
	sz += last * 2;
	a += 1ll * (last + 1) * (mxx - mnx - 1);
	printf("%lld %lld %lld\n", c, sz, a);
	return 0;
}
