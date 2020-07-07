/*
 * 850B. Arpa and a list of numbers.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int n, lim, cnt[MAXN];
long long x, y, sum[MAXN];

long long solve(int g) {
	long long ret = 0;
	for (int i = 1; g * (i - 1) + 1 < MAXN; i++) {
		int s = g * (i - 1) + 1, e = min(g * i, MAXN - 1);
		int mid = min(e, max(s, g * i - lim + 1));
		ret += x * (cnt[mid - 1] - cnt[s - 1]);
		ret += y
				* (1ll * g * i * (cnt[e] - cnt[mid - 1])
						- (sum[e] - sum[mid - 1]));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%lld%lld", &n, &x, &y);
	lim = (x + y - 1) / y;
	while (n--) {
		int a;
		scanf("%d", &a);
		cnt[a]++, sum[a] += a;
	}
	for (int i = 1; i < MAXN; i++)
		sum[i] += sum[i - 1], cnt[i] += cnt[i - 1];
	long long ans = 1e18;
	for (int i = 2; i < MAXN; i++)
		ans = min(ans, solve(i));
	printf("%lld\n", ans);
	return 0;
}
