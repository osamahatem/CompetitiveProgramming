/*
 * 305D. Olya and Graph.cpp
 *
 *  Created on: Dec 7, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long MOD = 1000000007;

long long dp[1000005][2];
int E, N, K;

long long solve(int idx, bool flag) {
	if (idx == E)
		return 1;
	long long &ret = dp[idx][flag];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1, flag);
	if (!flag && idx + K + 1 <= N)
		ret = (ret + solve(idx + 1, flag)) % MOD;
	if (idx - K - 1 > 0)
		ret = (ret + solve(idx + 1, 1)) % MOD;
	return ret;
}

long long fastPower(long long b, long long p) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % MOD;
		b = b * b % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, k, u, v;
	vector<pair<int, int> > edges;
	cin >> n >> m >> k;
	while (m--) {
		cin >> u >> v;
		if (v - u != 1 && v - u != k + 1) {
			cout << "0\n";
			return 0;
		}
		if (v - u == k + 1) {
			if (edges.size() && u >= edges[0].second) {
				cout << "0\n";
				return 0;
			}
			edges.push_back(make_pair(u, v));
		}
	}
	long long ans = 1;
	if (edges.size()) {
		int j = 1;
		for (int i = edges[0].first + 1; i < edges.back().first; i++) {
			if (edges[j].first == i) {
				j++;
				continue;
			}
			ans = ans * 2 % MOD;
		}
		memset(dp, -1, sizeof dp);
		E = edges[0].second, N = n, K = k;
		ans = (ans * solve(edges.back().first + 1, 0)) % MOD;
	} else {
		int last = n - k - 1;
		for (int i = 1; i <= last; i++) {
//			cout << i << " " << min(k, last - i) << endl;
			ans = (ans + fastPower(2, min(k, last - i))) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
