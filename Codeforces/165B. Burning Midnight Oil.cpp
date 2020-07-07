/*
 * 165B. Burning Midnight Oil.cpp
 *
 *  Created on: Aug 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k;

bool check(int v) {
	long long all = v, kk = k;
	while (v / kk) {
		all += v / kk;
		kk *= k;
	}
	return all >= n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> k;
	int s = 0, e = n;
	while (s < e) {
		int mid = (s + e) / 2;
		if (check(mid))
			e = mid;
		else
			s = mid + 1;
	}
	cout << s << endl;
	return 0;
}
