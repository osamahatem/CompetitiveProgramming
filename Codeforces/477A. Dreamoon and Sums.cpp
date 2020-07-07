/*
 * 477A. Dreamoon and Sums.cpp
 *
 *  Created on: Oct 12, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long a, b, ans = 0;
	cin >> a >> b;
	long long suma = (a * (a + 1) / 2) % MOD;
	for (long long i = 1; i < b; i++) {
		ans = (ans + i * a) % MOD;
		ans = (ans + (b * suma % MOD) * i % MOD) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
