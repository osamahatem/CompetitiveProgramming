/*
 * G. Hayfa The Contestant.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long check(long long x) {
	long long ret = 0;
	while (x) {
		ret += x / 5;
		x /= 5;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("hayfa.in", "r", stdin);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		long long m, s = 0, e = 1ll << 60;
		cin >> m;
		while (s < e) {
			long long mid = (s + e) / 2;
			if (check(mid) < m)
				s = mid + 1;
			else
				e = mid;
		}
		cout << "Case " << i << ": " << s << endl;
	}
	return 0;
}
