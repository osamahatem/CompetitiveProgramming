/*
 * J. Just Terraffic!.cpp
 *
 *  Created on: Oct 12, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;

int n, t[MAXN];
int dp[MAXN][4];

int solve(int idx, int cnt) {
	if (idx == n)
		return 0;
	int &ret = dp[idx][cnt];
	if (~ret)
		return ret;
	int diff = t[idx + 1] - t[idx];
	if (diff <= 1000 && cnt < 3) {
		int temp = solve(idx + 1, cnt + 1);
		return ret = temp;
	}
	if (diff >= 2000 && cnt >= 2) {
		int temp = solve(idx + 1, 1);
		if (temp >= n)
			return ret = temp;
		return ret = temp + (cnt == 2);
	}
	if (diff > 1000 && diff < 2000) {
		int a = -1, b = -1;
		if (cnt >= 2)
			a = solve(idx + 1, 1);
		if (cnt < 3)
			b = solve(idx + 1, cnt + 1);
		if (a == n)
			return ret = a;
		if (b == n)
			return ret = b;
		if (a == n + 1)
			a = -1;
		if (b == n + 1)
			b = -1;
		if (a != -1)
			a += (cnt == 2);
		if (a != -1 && b != -1)
			return ret = (a == b ? a : n);
		else if (a != -1 || b != -1)
			return ret = (a == -1 ? b : a);
	}
	return ret = n + 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	t[n] = t[n - 1] + 5000;
	int cnt = solve(0, 1);
	if (cnt == n)
		printf("Ambiguous\n");
	else if (cnt == n + 1)
		printf("Impossible\n");
	else {
		printf("Cars without trailers: %d\n", cnt);
		printf("Cars with trailers: %d\n", (n - cnt * 2) / 3);
	}
	return 0;
}
