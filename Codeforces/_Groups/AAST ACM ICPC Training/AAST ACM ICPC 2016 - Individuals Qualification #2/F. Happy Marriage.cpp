/*
 * F. Happy Marriage.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int deg[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

//	freopen("happy.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(deg, 0, sizeof deg);
		int n, f, m;
		scanf("%d%d%d", &n, &f, &m);
		while (f--) {
			int u, v;
			scanf("%d%d", &u, &v);
			deg[u]++, deg[v]++;
		}
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			int ans = deg[u] + deg[v];
			printf("%s\n", ans & 1 ? "UNHAPPY" : "HAPPY");
		}
	}
	return 0;
}
