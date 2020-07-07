/*
 * 526B. Om Nom and Dark Park.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int maxi[4100], lights[4100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < (1 << (n + 1)) - 2; i++)
		cin >> lights[i + 2];
	for (int i = (1 << (n + 1)) - 1; i > 0; i--) {
		ans += 2 * maxi[i] - lights[i * 2] - maxi[i * 2] - lights[i * 2 + 1]
				- maxi[i * 2 + 1];
		maxi[i / 2] = max(maxi[i / 2], maxi[i] + lights[i]);
	}
	cout << ans << endl;
	return 0;
}
