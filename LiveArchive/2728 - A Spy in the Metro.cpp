/*
 * 2728 - A Spy in the Metro.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: Osama Hatem
 */
 
/*
All times are positive, so there are no cycles and can be solved with DP.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXT = 205;
const int MAXN = 55;

int n, T, dist[MAXN], dp[MAXN][MAXT];
bool train[MAXN][MAXT][2];

int solve(int idx, int t) {
	if (t > T)
		return MAXT;
	if (t == T && idx == n - 1)
		return 0;
	int &ret = dp[idx][t];
	if (~ret)
		return ret;
	ret = 1 + solve(idx, t + 1);
	if (train[idx][t][0])
		ret = min(ret, solve(idx + 1, t + dist[idx + 1]));
	if (train[idx][t][1])
		ret = min(ret, solve(idx - 1, t + dist[idx]));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t = 0;
	while (cin >> n >> T, n) {
		memset(train, 0, sizeof train);
		memset(dp, -1, sizeof dp);
		for (int i = 1; i < n; i++)
			cin >> dist[i];
		int k, off;
		cin >> k;
		while (k--) {
			cin >> off;
			for (int i = 0; off < MAXT && i + 1 < n; i++) {
				train[i][off][0] = 1;
				off += dist[i + 1];
			}
		}
		cin >> k;
		while (k--) {
			cin >> off;
			for (int i = n - 1; off < MAXT && i; i--) {
				train[i][off][1] = 1;
				off += dist[i];
			}
		}
		int ans = solve(0, 0);
		cout << "Case Number " << ++t << ": ";
		if (ans >= MAXT)
			cout << "impossible" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
