/*
 * 195E. Building Forest.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, root[MAXN];
long long depth[MAXN];

int find(int v) {
	if (root[v] == v)
		return v;
	int r = find(root[v]);
	depth[v] = (depth[v] + depth[root[v]]) % MOD;
	return root[v] = r;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		root[i] = i, depth[i] = 0;
		int k;
		scanf("%d", &k);
		while (k--) {
			int v, x;
			scanf("%d%d", &v, &x);
			int r = find(v);
			ans = (ans + depth[v] + x) % MOD;
			if (ans < 0)
				ans += MOD;
			root[r] = i;
			depth[r] = (depth[r] + depth[v] + x) % MOD;
			if (depth[r] < 0)
				depth[r] += MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
