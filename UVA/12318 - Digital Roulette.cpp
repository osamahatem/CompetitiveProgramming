/*
 * 12318 - Digital Roulette.cpp
 *
 *  Created on: Aug 25, 2014
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

	int n, m, k;
	long long coeff[11];
	set<long long> ans;
	while (cin >> n >> m >> k, n) {
		ans.clear();
		for (int i = 0; i <= k; i++)
			cin >> coeff[i];
		++n;
		for (int i = 0; i <= m; i++) {
			long long p = 1;
			long long x = 0;
			for (int j = 0; j <= k; j++) {
				x = (x + p * coeff[j]) % n;
				p = (p * i) % n;
			}
			ans.insert(x);
		}
		cout << ans.size() << "\n";
	}
	return 0;
}
