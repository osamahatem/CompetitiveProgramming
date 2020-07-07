/*
 * 456C. Boredom.cpp
 *
 *  Created on: Aug 8, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

long long cnt[MAXN], memo[MAXN];

long long solve(int n) {
	if (n >= MAXN)
		return 0;
	long long &ret = memo[n];
	if (ret != -1)
		return ret;
	if (cnt[n] == 0)
		return ret = solve(n + 1);
	return ret = max(solve(n + 1), cnt[n] * n + solve(n + 2));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(memo, -1, sizeof memo);
	int n, x;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		cnt[x]++;
	}
	printf("%I64d\n", solve(0));
	return 0;
}
