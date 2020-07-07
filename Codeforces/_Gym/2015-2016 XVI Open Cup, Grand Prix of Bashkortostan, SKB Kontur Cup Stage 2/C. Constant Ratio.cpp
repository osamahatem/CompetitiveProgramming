/*
 * C. Constant Ratio.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;

long long powLog(long long b, int p) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret *= b;
		b *= b;
	}
	return ret;
}

bool check(int ss, int r) {
	if (r == 1)
		return (n % ss ? 0 : 1);
	int s = 1, e = (int) (log(n) / log(r) + 2.0);
	while (s < e) {
		int mid = (s + e + 1) / 2;
		long long temp = powLog(r, mid + 1) - 1;
		temp /= r - 1;
		temp *= ss;
		if (temp > n)
			e = mid - 1;
		else
			s = mid;
	}
	long long temp = powLog(r, s + 1) - 1;
	temp /= r - 1;
	temp *= ss;
	return temp == n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	int ans = 0;
	for (int r = 1; r < n; r++) {
		for (int i = 1; i + i * r <= n; i++)
			ans += check(i, r);
	}
	cout << ans << endl;
	return 0;
}
