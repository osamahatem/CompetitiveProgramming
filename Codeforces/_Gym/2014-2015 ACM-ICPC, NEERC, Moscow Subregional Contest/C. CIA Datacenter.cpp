/*
 * C. CIA Datacenter.cpp
 *
 *  Created on: Oct 4, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long a, b, c;

long long check(long long disk, long long cont) {
	long long shared = disk % cont;
	long long dpc = disk / cont;
	return shared * min(b, (dpc + 1) * a) + (cont - shared) * min(b, dpc * a);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> a >> b >> c;
	if (b < a) {
		long long ans = (c + b - 1) / b;
		cout << ans << " " << ans << endl;
	} else {
		long long disks = (c + a - 1) / a;
		long long s = 1, e = disks;
		while (s < e) {
			long long mid = (s + e) / 2;
			if (check(disks, mid) < c)
				s = mid + 1;
			else
				e = mid;
		}
		cout << disks << " " << s << endl;
	}
	return 0;
}
