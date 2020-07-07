/*
 * 477A. Dreamoon and Sums - O(1).cpp
 *
 *  Created on: Aug 2, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	long long sumA = ((long long) a * (a + 1) / 2) % MOD;
	long long sumB = ((long long) b * (b - 1) / 2) % MOD;
	long long ans = sumB * ((a + b * sumA) % MOD) % MOD;
	cout << ans << endl;
	return 0;
}
