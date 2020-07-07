/*
 * 2025. Line Fighting.cpp
 *
 *  Created on: Nov 4, 2014
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

	int t;
	long long n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		long long sum = 0, ans = 0;
		long long mod = n % k;
		for (int i = 0; i < k; i++) {
			long long cur = n / k;
			if (mod)
				cur++, mod--;
			ans += sum * cur;
			sum += cur;
		}
		cout << ans << endl;
	}
	return 0;
}
