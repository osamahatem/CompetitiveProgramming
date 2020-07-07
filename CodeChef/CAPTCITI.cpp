/*
 * CAPTCITI.cpp
 *
 *  Created on: Jun 2, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e4 + 5;

int n, head[MAXN], nxt[MAXN << 1], to[MAXN << 1], last;
long long p[MAXN], c[MAXN];
long long dp[MAXN][2];

void addEdge(int u, int v) {
	to[last] = v;
	nxt[last] = head[u];
	head[u] = last++;
}

void init() {
	memset(dp, -1, sizeof dp);
	memset(head, -1, sizeof head);
	last = 0;
}

long long solve(int idx, int par, bool flag) {
	long long &ret = dp[idx][flag];
	if (~ret)
		return ret;
	ret = p[idx];
	long long sum_op0 = 0;
	int ch = 0;
	vector<long long> temp;
	for (int e = head[idx]; ~e; e = nxt[e]) {
		if (to[e] == par)
			continue;
		ch++;
		long long op0 = solve(to[e], idx, 0);
		long long op1 = solve(to[e], idx, 1);
		sum_op0 += op0;
		ret += op1;
		temp.push_back(op1 - op0);
	}
	int need = ch - (c[idx] - flag);
	if (~need) {
		sort(temp.begin(), temp.end());
		for (int i = 0; i < need; i++)
			sum_op0 += temp[i];
		ret = min(ret, sum_op0);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d", &n);
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v), addEdge(v, u);
		}
		for (int i = 1; i <= n; i++)
			scanf("%lld", &p[i]);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &c[i]);
		printf("%lld\n", solve(1, 0, 0));
	}
	return 0;
}
