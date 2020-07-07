/*
 * D. factors.cpp
 *
 *  Created on: Sep 7, 2015
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

	freopen("factors.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, k, dig[10], ans = 0;
		vector<int> fact;
		cin >> n >> k;
		for (int i = 2; i <= n / i; i++)
			if (n % i == 0) {
				fact.push_back(i), n /= i;
				i--;
			}
		if (n > 1)
			fact.push_back(n);
		int sz = fact.size();
		for (int i = (1 << sz) - 1; i; i--) {
			int temp = 0;
			for (int j = 0; j < sz; j++)
				temp += fact[j] * (bool) (i & (1 << j));
			if (temp <= ans)
				continue;
			memset(dig, 0, sizeof dig);
			bool flag = 1;
			for (int j = 0; j < sz && flag; j++)
				if (i & (1 << j)) {
					int x = fact[j];
					while (x) {
						dig[x % 10]++;
						if (dig[x % 10] > k) {
							flag = 0;
							break;
						}
						x /= 10;
					}
				}
			if (flag)
				ans = temp;
		}
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
