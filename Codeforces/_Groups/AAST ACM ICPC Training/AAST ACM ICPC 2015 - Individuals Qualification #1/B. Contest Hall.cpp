/*
 * B. Contest Hall.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int sq[2050][2050], x[1005], y[1005];

bool val(int x) {
	return x > 0 && x < 2050;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("contesthall.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, ans = -1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			x[i] += 1010, y[i] += 1010;
			sq[x[i]][y[i]] = t;
		}
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (x[i] == x[j] && y[i] == y[j])
					continue;
				int dx = x[i] - x[j], dy = y[i] - y[j];
				int x1 = x[i] - dy, y1 = y[i] + dx;
				int x2 = x[j] - dy, y2 = y[j] + dx;
				if (!val(x1) || !val(y1) || !val(x2) || !val(y2))
					continue;
				if (sq[x1][y1] == t && sq[x2][y2] == t)
					ans = max(ans, dx * dx + dy * dy);
			}
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
