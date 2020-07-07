/*
 ID: 19semse1
 PROG: wormhole
 LANG: C++
 */
/*
 * wormhole.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, ans;
pair<int, int> arr[12];

int getNext(int x, int y) {
	int nx = 1 << 30, ret = -1;
	for (int i = 0; i < n; i++)
		if (arr[i].second == y && arr[i].first > x && arr[i].first < nx)
			ret = i, nx = arr[i].first;
	return ret;
}

void test() {
	bool vis[12];
	for (int i = 0; i < n; i++) {
		memset(vis, 0, sizeof vis);
		int cy = arr[i].second, cx = arr[i].first - 1, c;
		while (1) {
			c = getNext(cx, cy);
			if (c == -1)
				break;
			c ^= 1;
			if (vis[c])
				break;
			vis[c] = 1;
			cx = arr[c].first, cy = arr[c].second;
		}
		if (c != -1) {
			ans++;
			return;
		}
	}
}

void solve(int idx) {
	if (idx == n) {
		test();
		return;
	}
	for (int i = idx + 1; i < n; i++) {
		swap(arr[idx + 1], arr[i]);
		solve(idx + 2);
		swap(arr[idx + 1], arr[i]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	solve(0);
	cout << ans << endl;
	return 0;
}
