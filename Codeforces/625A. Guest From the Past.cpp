/*
 * 625A. Guest From the Past.cpp
 *
 *  Created on: Mar 15, 2016
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

	long long n, a, b, c, ans = 0;
	cin >> n >> a >> b >> c;
	if (a <= b - c)
		ans = n / a;
	else {
		long long s = 0, e = n / (b - c);
		while (s < e) {
			long long mid = (s + e + 1) / 2;
			long long nn = n - mid * (b - c);
			if (nn + b - c < b)
				e = mid - 1;
			else
				s = mid;
		}
		ans = s;
		n -= s * (b - c);
		ans += n / a;
	}
	cout << ans << endl;
	return 0;
}
