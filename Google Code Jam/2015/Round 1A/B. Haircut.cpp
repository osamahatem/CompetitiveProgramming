/*
 * B. Haircut.cpp
 *
 *  Created on: Apr 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, b, m[1005], mini = 1 << 30;
		cin >> b >> n;
		for (int i = 0; i < b; i++) {
			cin >> m[i];
			mini = min(mini, m[i]);
		}
		long long s = 0, e = (long long) n * mini, finished;
		while (s < e) {
			long long mid = s + (e - s) / 2;
			finished = 0;
			for (int i = 0; i < b; i++)
				finished += mid / m[i] + 1;
			if (finished < n)
				s = mid + 1;
			else
				e = mid;
		}
		int ans;
		finished = 0;
		for (int i = 0; i < b; i++)
			finished += (s - 1) / m[i] + 1;
		for (int i = 0; i < b; i++) {
			if (s % m[i] == 0)
				finished++;
			if (finished == n) {
				ans = i + 1;
				break;
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
