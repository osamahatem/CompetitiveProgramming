/*
 * K. New GPU.cpp
 *
 *  Created on: May 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int a, b, p;

long long check(long long n) {
	double ret = sqrt(n) * b + pow(n, 1.0 / 3.0) * a;
	return (long long) (floor(ret) + 1e-9);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> a >> b >> p;
	long long s = 0, e = 1ll << 60;
	while (s < e) {
		long long mid = (s + e) / 2;
		if (check(mid) < p)
			s = mid + 1;
		else
			e = mid;
	}
	cout << s << endl;
	return 0;
}
