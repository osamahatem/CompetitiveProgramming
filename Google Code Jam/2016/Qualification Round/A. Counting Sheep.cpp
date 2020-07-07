/*
 * A. Counting Sheep.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[10];

int update(int n) {
	int ret = 0;
	while (n) {
		int x = n % 10;
		ret += !vis[x];
		vis[x] = 1;
		n /= 10;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		cout << "Case #" << t << ": ";
		if (!n) {
			cout << "INSOMNIA" << endl;
			continue;
		}
		memset(vis, 0, sizeof vis);
		int cnt = 0, x = 0;
		while (cnt < 10) {
			x += n;
			cnt += update(x);
		}
		cout << x << endl;
	}
	return 0;
}
