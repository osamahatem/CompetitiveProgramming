/*
 * 897B. Chtholly's request.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int rev(int x) {
	int ret = 0;
	while (x) {
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int k, p, ans = 0;
	cin >> k >> p;
	int s = 1, ex = 10;
	while (k) {
		for (int i = s; i < 10 * s && k; k--, i++)
			ans = (1ll * i * ex + rev(i) + ans) % p;
		s *= 10, ex *= 10;
	}
	cout << ans << endl;
	return 0;
}
