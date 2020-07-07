/*
 * 12485 - Perfect Choir.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
vector<int> all;

int valid(int x) {
	int diff = 0;
	for (int i = 0; i < n; i++)
		diff += x - all[i];
	return diff;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (cin >> n) {
		all.resize(n);
		for (int i = 0; i < n; i++)
			cin >> all[i];
		int s = all[0], e = all[n - 1], med = -1;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (valid(mid) < 0)
				s = mid + 1;
			else if (valid(mid) > 0)
				e = mid - 1;
			else {
				med = mid;
				break;
			}
		}
		int ans = 0;
		if (med != -1) {
			for (int i = 0; i < n; i++)
				ans += abs(med - all[i]);
			ans = ans / 2 + 1;
		} else
			ans = -1;
		cout << ans << "\n";
	}
	return 0;
}
