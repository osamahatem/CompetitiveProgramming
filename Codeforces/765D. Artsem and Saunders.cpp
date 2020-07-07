/*
 * 765D. Artsem and Saunders.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, f[MAXN], pos[MAXN], h[MAXN], g[MAXN];
set<int> uni;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
		uni.insert(f[i]);
	}
	for (auto it = uni.begin(); it != uni.end(); it++) {
		int x = *it;
		if (f[x] != x) {
			puts("-1");
			return 0;
		}
		h[++m] = x;
		pos[x] = m;
	}
	for (int i = 1; i <= n; i++)
		g[i] = pos[f[i]];
	printf("%d\n", m);
	for (int i = 1; i <= n; i++) {
		if (i > 1)
			printf(" ");
		printf("%d", g[i]);
	}
	printf("\n");
	for (int i = 1; i <= m; i++) {
		if (i > 1)
			printf(" ");
		printf("%d", h[i]);
	}
	printf("\n");
	return 0;
}
