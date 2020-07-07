/*
 * 189A. Cut Ribbon.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, b, c, ans = 0;
	cin >> n >> a >> b >> c;
	for (int i = 0; i * a <= n; i++)
		for (int j = 0; j * b + i * a <= n; j++) {
			if ((n - i * a - j * b) % c)
				continue;
			int k = (n - i * a - j * b) / c;
			ans = max(ans, i + j + k);
		}
	cout << ans << endl;
	return 0;
}
