/*
 * 2.Marathon.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int INF = 1 << 28;

int N, K, dp[505][505];
pair<int, int> all[505];

int dist(pair<int, int> a, pair<int, int> b) {
	int dx = abs(a.first - b.first);
	int dy = abs(a.second - b.second);
	return dx + dy;
}

int solve(int k, int idx) {
	if (idx == N)
		return 0;
	int &ret = dp[k][idx];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 0; i <= k && idx + i + 1 <= N; i++)
		ret = min(ret,
				dist(all[idx], all[idx + i + 1]) + solve(k - i, idx + i + 1));
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
//#endif

	memset(dp, -1, sizeof dp);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> all[i].first >> all[i].second;
	cout << solve(K, 1) << endl;
	return 0;
}
