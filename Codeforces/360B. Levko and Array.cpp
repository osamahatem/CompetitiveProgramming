/*
 * 360B. Levko and Array.cpp
 *
 *  Created on: Jun 3, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2005;

int N, K, arr[MAXN];
int dp[MAXN];

int solve(int idx, int maxi) {
	if (idx == N + 1)
		return 0;
	int &ret = dp[idx];
	if (~ret)
		return ret;
	ret = MAXN;
	for (int i = idx + 1; i <= N + 1; i++) {
		int diff = (!idx || i == N + 1 ? 0 : abs(arr[idx] - arr[i]));
		if (1ll * maxi * (i - idx) < diff)
			continue;
		ret = min(ret, i - idx - 1 + solve(i, maxi));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	int s = 0, e = 2e9 + 5;
	while (s < e) {
		memset(dp, -1, sizeof dp);
		int mid = (1ll * s + e) / 2;
		if (solve(0, mid) <= K)
			e = mid;
		else
			s = mid + 1;
	}
	printf("%d\n", s);
	return 0;
}
