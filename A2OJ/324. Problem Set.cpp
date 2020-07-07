/*
 * 324. Problem Set.cpp
 *
 *  Created on: Nov 12, 2014
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

	int t, tc = 0;
	cin >> t;
	while (t--) {
		int n, m, x, y;
		int maxi = 0, mini = 300000;
		cin >> n >> m >> x >> y;
		while (n--) {
			int a, b, c;
			cin >> a >> b >> c;
			maxi = max(maxi, a + b + c);
			mini = min(mini, a + b + c);
		}
		int diff[10];
		for (int i = 0; i < m; i++)
			cin >> diff[i];
		sort(diff, diff + m);
		int mask = (1 << m) - 1, maxDiff = 0;
		for (int i = 0; i < (1 << m); i++) {
			int sum = 0, a = 0, b = 0;
			for (int p = 0; p < m; p++)
				if (i & (1 << p)) {
					sum += diff[m - 1 - p];
					if (diff[m - 1 - p] <= mini)
						a++;
					if (diff[m - 1 - p] <= maxi)
						b++;
				}
			if (a == x && b == y) {
				if (sum > maxDiff || (sum == maxDiff && i > mask)) {
					mask = i;
					maxDiff = sum;
				}
			}
		}
		cout << "Case " << ++tc << ":";
		if (maxDiff == 0)
			cout << " No Solution." << endl;
		else {
			for (int i = m - 1; i >= 0; i--)
				if (mask & (1 << i))
					cout << " " << diff[m - 1 - i];
			cout << endl;
		}
	}
	return 0;
}
