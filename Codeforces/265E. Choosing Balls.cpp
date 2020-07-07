/*
 * 265E. Choosing Balls.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const long long INF = 1e11;

int N, Q, col[MAXN];
long long val[MAXN], dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//  freopen("out.out", "w", stdout);
#endif

	cin >> N >> Q;
	for (int i = 0; i < N; i++)
		cin >> val[i];
	for (int i = 0; i < N; i++)
		cin >> col[i];
	while (Q--) {
		fill(dp, dp + MAXN, -INF);
		int a, b, max_idx[2] = { -1, -1 };
		long long ans = 0, temp, maxi[2] = { 0, 0 };
		cin >> a >> b;
		for (int i = 0; i < N; i++) {
			temp = val[i] * b + (max_idx[0] == col[i] ? maxi[1] : maxi[0]);
			temp = max(temp, dp[col[i]] + val[i] * a);
			dp[col[i]] = max(dp[col[i]], temp);
			if (col[i] == max_idx[0])
				maxi[0] = max(maxi[0], temp);
			else if (col[i] == max_idx[1]) {
				maxi[1] = max(maxi[1], temp);
				if (maxi[1] > maxi[0])
					swap(maxi[0], maxi[1]), swap(max_idx[0], max_idx[1]);
			} else if (temp > maxi[0]) {
				maxi[1] = maxi[0], max_idx[1] = max_idx[0];
				maxi[0] = temp, max_idx[0] = col[i];
			} else if (temp > maxi[1])
				maxi[1] = temp, max_idx[1] = col[i];
			ans = max(ans, temp);
		}
		cout << ans << "\n";
	}
	return 0;
}
