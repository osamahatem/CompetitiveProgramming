/*
 ID: 19semse1
 PROG: combo
 LANG: C++
 */
/*
 * combo.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool used[105][105][105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
#endif

	int n, a1, a2, b1, b2, c1, c2, ans = 0;
	cin >> n >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	a1--, a2--, b1--, b2--, c1--, c2--;
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			for (int k = -2; k <= 2; k++) {
				int ta = (a1 + i + n) % n, tb = (b1 + j + n) % n, tc = (c1 + k
						+ n) % n;
				if (!used[ta][tb][tc])
					ans++;
				used[ta][tb][tc] = 1;
				ta = (a2 + i + n) % n, tb = (b2 + j + n) % n, tc = (c2 + k + n)
						% n;
				if (!used[ta][tb][tc])
					ans++;
				used[ta][tb][tc] = 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
