/*
 * 515B. Drazil and His Happy Friends.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool gh[105], bh[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, c, x;
	cin >> n >> m;
	cin >> c;
	while (c--) {
		cin >> x;
		bh[x] = 1;
	}
	cin >> c;
	while (c--) {
		cin >> x;
		gh[x] = 1;
	}
	int b = 0, g = 0;
	bool change;
	do {
		change = 0;
		do {
			if (bh[b] ^ gh[g])
				bh[b] = gh[g] = 1, change = 1;
			b = (b + 1) % n;
			g = (g + 1) % m;
		} while (b || g);
	} while (change);
	bool ans = 1;
	for (int i = 0; i < n; i++)
		ans &= bh[i];
	for (int i = 0; i < m; i++)
		ans &= gh[i];
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
