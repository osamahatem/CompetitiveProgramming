/*
 * 53B. Blog Photo.cpp
 *
 *  Created on: Aug 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

pair<int, int> cmp(pair<int, int> a, pair<int, int> b) {
	int h1 = a.first, w1 = a.second, h2 = b.first, w2 = b.second;
	if (1ll * h1 * w1 != 1ll * h2 * w2)
		return (1ll * h1 * w1 > 1ll * h2 * w2 ? a : b);
	return max(a, b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int h, w;
	cin >> h >> w;
	pair<int, int> ans(1, 1);
	for (int i = 1; i <= h; i *= 2) {
		int nw = min(1ll * w, 1ll * i * 125 / 100);
		if ((double) i / nw + EPS < 0.8 || (double) i / nw - EPS > 1.25)
			continue;
		ans = cmp(ans, make_pair(i, nw));
	}
	for (int i = 1; i <= w; i *= 2) {
		int nh = min(1ll * h, 1ll * i * 125 / 100);
		if ((double) nh / i + EPS < 0.8 || (double) nh / i - EPS > 1.25)
			continue;
		ans = cmp(ans, make_pair(nh, i));
	}
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
