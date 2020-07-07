/*
 * 12482 - Short Story Competition.cpp
 *
 *  Created on: Aug 24, 2014
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

	int n, l, c;
	while (cin >> n >> l >> c) {
		int ans = 0, cur = 0;
		string temp;
		bool first = 1;
		while (n--) {
			cin >> temp;
			if (!first)
				cur++;
			cur += temp.size();
			if (cur > c) {
				ans++;
				cur = temp.size();
			}
			first = 0;
		}
		ans++;
		ans = ans / l + (bool) (ans % l);
		cout << ans << "\n";
	}
	return 0;
}
