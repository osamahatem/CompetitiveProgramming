/*
 * B. Infinite House of Pancakes.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int d, p[1005], ans = 0;
		cin >> d;
		for (int i = 0; i < d; i++)
			cin >> p[i], ans = max(ans, p[i]);
		for (int i = 1; i < ans; i++) {
			int temp = i;
			for (int j = 0; j < d; j++) {
				if (p[j] <= i)
					continue;
				int x = p[j] - i;
				temp += x / i;
				if (x % i)
					temp++;
			}
			ans = min(temp, ans);
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
