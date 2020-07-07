/*
 * 507C. Guess Your Way Out!.cpp
 *
 *  Created on: Jan 25, 2015
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

	int h;
	long long tar, cur = 0, ans = 0;
	bool flag = 0;
	cin >> h >> tar;
	tar += (1ll << h) - 2;
	while (cur != tar) {
		long long mini = (cur + 1) * (1ll << h) - 1;
		long long maxi = cur * (1ll << h) + (1ll << (h + 1)) - 2;
		if (tar < mini || tar > maxi || !h) {
			ans += (1ll << (h + 1)) - 1;
			cur = (cur - 1) / 2;
			ans--, h++;
		} else {
			ans++, h--;
			cur = cur * 2 + 1 + flag;
			flag = !flag;
		}
	}
	cout << ans << endl;
	return 0;
}
