/*
 * 347B. Fixed Points.cpp
 *
 *  Created on: Aug 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int pos[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pos[x] = i;
		ans += x == i;
	}
	if (ans < n)
		ans++;
	for (int i = 0; i < n; i++) {
		if (pos[i] == i)
			continue;
		if (pos[pos[i]] == i) {
			ans++;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
