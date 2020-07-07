/*
 * A. Ample Syrup.cpp
 *
 *  Created on: Apr 30, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double PI = acos(-1.0);

double dp[1005][1005];
bool vis[1005][1005];
int N, K;
pair<int, int> cake[1005];

double solve(int idx, int k) {
	if (idx == N)
		return k ? -(1e18) : 0.0;
	if (vis[idx][k])
		return dp[idx][k];
	double ans = 2.0 * PI * cake[idx].first * cake[idx].second;
	if (k == 1)
		ans += PI * cake[idx].first * cake[idx].first;
	ans += solve(idx + 1, k - 1);
	ans = max(ans, solve(idx + 1, k));
	vis[idx][k] = 1;
	return dp[idx][k] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(vis, 0, sizeof vis);
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; i++)
			scanf("%d%d", &cake[i].first, &cake[i].second);
		sort(cake, cake + N);
		printf("Case #%d: %.6f\n", t, solve(0, K));
	}
	return 0;
}
