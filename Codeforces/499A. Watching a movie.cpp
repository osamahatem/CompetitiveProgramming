/*
 * 499A. Watching a movie.cpp
 *
 *  Created on: Dec 24, 2014
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

	int n, x, cur = 1, ans = 0, l, r;
	cin >> n >> x;
	while (n--) {
		cin >> l >> r;
		while (cur + x <= l)
			cur += x;
		ans += r - cur + 1;
		cur = r + 1;
	}
	cout << ans << endl;
	return 0;
}
