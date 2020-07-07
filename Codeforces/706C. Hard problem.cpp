/*
 * 706C. Hard problem.cpp
 *
 *  Created on: Aug 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long INF = 1ll << 60;

int n, arr[100000];
string all[100000][2];
char in[100005];
long long dp[100000][2];

long long solve(int idx, int rev) {
	if (idx == n - 1)
		return 0;
	long long &ret = dp[idx][rev];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int j = 0; j < 2; j++)
		if (all[idx][rev] <= all[idx + 1][j])
			ret = min(ret, solve(idx + 1, j) + (j ? arr[idx + 1] : 0));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		scanf("%s", in);
		all[i][0] = all[i][1] = in;
		reverse(all[i][1].begin(), all[i][1].end());
	}
	memset(dp, -1, sizeof dp);
	long long ans = min(solve(0, 0), solve(0, 1) + arr[0]);
	if (ans == INF)
		ans = -1;
	printf("%lld\n", ans);
	return 0;
}
