/*
 * 448D. Multiplication Table.cpp
 *
 *  Created on: Feb 23, 2015
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

	int n, m;
	long long k;
	cin >> n >> m >> k;
	long long s = 1, e = (long long) n * m;
	while (s < e) {
		long long mid = (s + e) / 2;
		long long lt = 0, lte = 0;
		for (int i = 1; i <= n; i++) {
			lt += min((long long) m, (mid - 1) / i);
			lte += min((long long) m, mid / i);
		}
		if (lte < k)
			s = mid + 1;
		else {
			e = mid;
			if (lt == lte || lt > k)
				e--;
		}
	}
	cout << s << endl;
	return 0;
}
