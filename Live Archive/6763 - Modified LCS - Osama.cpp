/*
 * 6763 - Modified LCS.cpp
 *
 *  Created on: Aug 20, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

long long x, y;

long long extendedGCD(long long a, long long b) {
	if (!a) {
		x = 0, y = 1;
		return b;
	}
	long long gcd = extendedGCD(b % a, a);
	long long x1 = x, y1 = y;
	x = y1 - b / a * x1;
	y = x1;
	return gcd;
}

long long cast(double x) {
	x += (x > 0 ? EPS : -EPS);
	return (long long) x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	while (T--) {
		long long n1, n2, f1, f2, d1, d2;
		cin >> n1 >> f1 >> d1 >> n2 >> f2 >> d2;
		int gcd = extendedGCD(d1, d2);
		if ((f2 - f1) % gcd != 0) {
			cout << "0" << endl;
			continue;
		}
		long long lcm = 1ll * d1 * d2 / gcd;
		if (f1 == f2) {
			long long l1 = lcm / d1, l2 = lcm / d2;
			cout << min((n1 + l1 - 1) / l1, (n2 + l2 - 1) / l2) << endl;
			continue;
		}
		y *= (f1 - f2) / gcd, x *= (f2 - f1) / gcd;
		double kl = -1.0 * x * gcd / d2;
		double kh = -1.0 * y * gcd / d1;
		long long k = max(cast(ceil(kl)), cast(ceil(kh)));
		x += k * (d2 / gcd), y += k * (d1 / gcd);
		if (x < 0 || y < 0 || x >= n1 || y >= n2) {
			cout << "0" << endl;
			continue;
		}
		long long temp = lcm / d1;
		long long res = (n1 - x + temp - 1) / temp;
		temp = lcm / d2;
		res = min(res, (n2 - y + temp - 1) / temp);
		cout << res << endl;
	}
	return 0;
}
