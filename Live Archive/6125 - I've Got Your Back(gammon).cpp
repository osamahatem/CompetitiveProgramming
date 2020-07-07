/*
 * 6125 - I've Got Your Back(gammon).cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int all[16000], c = 0;

void init(int idx, int left, int cur) {
	if (idx == 0) {
		cur += left;
		all[c++] = cur;
		return;
	}
	for (int i = 0; i <= left; i++)
		init(idx - 1, left - i, cur + i * (1 << (4 * idx)));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	init(5, 15, 0);
	char q;
	int tc = 0, ans[5];
	while (cin >> q, q != 'e') {
		cout << "Case " << ++tc << ":";
		if (q == 'u') {
			int x;
			cin >> x;
			x = all[x];
			for (int i = 0; i < 6; i++) {
				ans[5 - i] = x % 16;
				x /= 16;
			}
			for (int i = 0; i < 6; i++)
				cout << " " << ans[i];
			cout << endl;
		} else {
			int x, cur = 0, idx = 5;
			while (idx >= 0) {
				cin >> x;
				cur += x * (1 << (4 * idx));
				idx--;
			}
			idx = lower_bound(all, all + c, cur) - all;
			cout << " " << idx << endl;
		}
	}
	return 0;
}
