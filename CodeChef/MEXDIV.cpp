/*
 * MEXDIV.cpp
 *
 *  Created on: Jun 5, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;

int N, k, arr[MAXN];
int last[MAXN], lim[MAXN];
int dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(last, -1, sizeof last);
	scanf("%d%d", &N, &k);
	k = min(k, N + 2);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	queue<int> Q;
	int cnt = 0;
	for (int i = N - 1; ~i; i--) {
		if (arr[i] <= k) {
			if (last[arr[i]] == -1)
				cnt++;
			last[arr[i]] = i;
			Q.push(i);
		}
		while (Q.size() && Q.front() > last[arr[Q.front()]])
			Q.pop();
		lim[i] = ((cnt == k + 1) ? Q.front() : N);
	}
	dp[N] = 1;
	for (int i = N - 1; ~i; i--) {
		dp[i] = (dp[i + 1] - dp[lim[i] + 1] + MOD) % MOD;
		dp[i] = (dp[i] + dp[i + 1]) % MOD;
	}
	printf("%d\n", (dp[0] - dp[1] + MOD) % MOD);
	return 0;
}
