/*
 * 471C. MUH and House of Cards.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long minNeed(long long h) {
	return h * (h + 1) + h * (h - 1) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long n;
	cin >> n;
	int ans = 0;
	for (int h = 1; minNeed(h) <= n; h++) {
		if ((n - minNeed(h)) % 3 == 0)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
