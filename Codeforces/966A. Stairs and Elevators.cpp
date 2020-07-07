/*
 * 966A. Stairs and Elevators.cpp
 *
 *  Created on: Apr 29, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXC = 1e5 + 5;

int n, m, cs, ce, v, q;
int st[MAXC], el[MAXC];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> cs >> ce >> v;
	for (int i = 0; i < cs; i++)
		cin >> st[i];
	for (int i = 0; i < ce; i++)
		cin >> el[i];

	cin >> q;
	while (q--) {
		int x1, y1, x2, y2, ans = 1e9;
		cin >> x1 >> y1 >> x2 >> y2;

		int idx = lower_bound(st, st + cs, y1) - st;
		if (idx < cs)
			ans = min(ans,
					abs(y1 - st[idx]) + abs(y2 - st[idx]) + abs(x1 - x2));
		idx--;
		if (~idx)
			ans = min(ans,
					abs(y1 - st[idx]) + abs(y2 - st[idx]) + abs(x1 - x2));

		idx = lower_bound(el, el + ce, y1) - el;
		if (idx < ce)
			ans = min(ans,
					abs(y1 - el[idx]) + abs(y2 - el[idx])
							+ (abs(x1 - x2) + v - 1) / v);
		idx--;
		if (~idx)
			ans = min(ans,
					abs(y1 - el[idx]) + abs(y2 - el[idx])
							+ (abs(x1 - x2) + v - 1) / v);

		if (x1 == x2)
			ans = abs(y1 - y2);

		cout << ans << endl;
	}
	return 0;
}
