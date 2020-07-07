/*
 * E. Meetings.cpp
 *
 *  Created on: Nov 16, 2017
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

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long l, v1, v2, t;
	cin >> l >> v1 >> v2 >> t;
	if (v1 > v2)
		swap(v1, v2);
	long long ans = t * v2 / l;
	long long rem2 = t * v2 % l, rem1 = t * v1 % l;
	long long dir1 = (t * v1 / l) & 1, dir2 = ((t * v2 / l) & 1) ? 0 : 1;
	if (dir1 == dir2)
		ans += (rem2 >= rem1 && rem1 && rem2);
	else
		ans += (rem2 + rem1) >= l;
	long long g = __gcd(v1, v2);
	long long x = v1 / g;
	long long y = x * v2 / v1;
	if ((y - x) & 1) {
		ans -= (t * v1 / l) / (x * 2);
		long long temp = (t * v1 / l) % (x * 2);
		if (temp > x || (temp == x && rem1))
			ans--;
	}
	cout << ans << endl;
	return 0;
}
