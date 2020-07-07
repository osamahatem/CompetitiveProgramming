/*
 * 552B. Vanya and Books.cpp
 *
 *  Created on: Jun 18, 2015
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

	int n, cur = 1, d = 1;
	long long pw = 10;
	cin >> n;
	long long ans = 0;
	while (pw <= n) {
		ans += (long long) d * (pw - cur);
		cur = pw;
		pw *= 10;
		d++;
	}
	ans += (long long) (n - cur + 1) * d;
	cout << ans << endl;
	return 0;
}
