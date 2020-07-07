/*
 * 12651 - Triangles.cpp
 *
 *  Created on: Aug 16, 2014
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

	int n, sum[100005];
	while (cin >> n) {
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> sum[i];
			sum[i] += sum[i - 1];
		}
		if (sum[n] % 3 != 0) {
			cout << "0\n";
			continue;
		}
		int r = sum[n] / 3, ans = 0;
		for (int i = 1; i < n; i++) {
			int a = lower_bound(sum, sum + n + 1, sum[i] + r) - sum;
			if (a > n)
				continue;
			int b = lower_bound(sum, sum + n + 1, sum[i] + 2 * r) - sum;
			if (b > n)
				continue;
			if (sum[a] == sum[i] + r && sum[b] == sum[i] + 2 * r)
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
