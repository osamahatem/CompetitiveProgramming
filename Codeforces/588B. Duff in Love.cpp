/*
 * 588B. Duff in Love.cpp
 *
 *  Created on: Oct 15, 2015
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

	long long ans = 1, n;
	cin >> n;
	for (long long i = 2; i * i <= n; i++)
		if (n % i == 0) {
			ans *= i;
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		ans *= n;
	cout << ans << endl;
	return 0;
}
