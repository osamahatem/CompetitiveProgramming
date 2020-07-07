/*
 * 479E. Riding in a Lift.cpp
 *
 *  Created on: Jun 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 5005;

int ans[MAXN], temp[MAXN];

int query(int s, int e) {
	int ret = ans[e] - ans[s - 1];
	if (ret < 0)
		ret += MOD;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, b, k;
	cin >> n >> a >> b >> k;
	for (int i = 1; i <= n; i++)
		ans[i] = 1 + ans[i - 1];
	for (int kk = 0; kk < k; kk++) {
		for (int i = 1; i <= n; i++) {
			int dist = abs(b - i) - 1;
			temp[i] = 0;
			if (dist > 0) {
				int s = max(i - dist, 1), e = min(i + dist, n);
				temp[i] = query(s, e) - query(i, i);
				if (temp[i] >= MOD)
					temp[i] -= MOD;
				if (temp[i] < 0)
					temp[i] += MOD;
			}
		}
		for (int i = 1; i <= n; i++) {
			ans[i] = temp[i] + ans[i - 1];
			if (ans[i] >= MOD)
				ans[i] -= MOD;
		}
	}
	int out = (ans[a] - ans[a - 1]) % MOD;
	if (out < 0)
		out += MOD;
	cout << out << endl;
	return 0;
}
