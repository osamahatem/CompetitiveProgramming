/*
 * 12447 - Pieces and Bits.cpp
 *
 *  Created on: Aug 4, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1 << 16;

int n, cnt[16], vis[MAXN], id = 1;

int comp(int x) {
	return (1 << n) - x - 1;
}

int next(int x, int b) {
	return comp(x) ^ (1 << b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		memset(cnt, 2, sizeof cnt);
		++id;
		scanf("%d", &n);
		int cur = 0;
		while (1) {
			for (int b = 0; b < n; b++) {
				int t = next(cur, b);
				if (vis[t] != id) {
					printf("%d\n", cur);
					vis[cur] = id;
					cnt[b]--;
					cur = t;
					b = -1;
				}
			}
			printf("%d\n", cur);
			break;
		}
	}
	return 0;
}
