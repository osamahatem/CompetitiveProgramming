/*
 * 913C. Party Lemonade.cpp
 *
 *  Created on: Jan 8, 2018
 *      Author: Osama Hatem
 */

/*
http://codeforces.com/blog/entry/56992
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long c[33];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		for (int j = 0; j < i; j++)
			c[i] = min(c[i], c[j] * (1 << (i - j)));
	}
	long long ans = -1, sum = 0;
	for (int i = n - 1; ~i; i--) {
		long long cur = 1 << i;
		long long temp = 1ll * (l + cur - 1) / cur * c[i];
		ans = ans == -1 ? (sum + temp) : min(ans, sum + temp);
		sum += c[i] * (l / cur);
		l -= l / cur * cur;
	}
	cout << ans << endl;
	return 0;
}
