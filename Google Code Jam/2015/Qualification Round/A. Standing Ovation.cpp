/*
 * A. Standing Ovation.cpp
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
		int s, sum = 0, ans = 0;
		string in;
		cin >> s >> in;
		for (int i = 0; i <= s; i++) {
			if (i > sum)
				ans += i - sum, sum += i - sum;
			sum += in[i] - '0';
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
