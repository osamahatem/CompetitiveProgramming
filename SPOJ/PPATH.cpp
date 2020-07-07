/*
 * PPATH.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 10000;

bool comp[MAXN];
int src, tar;

int BFS() {
	vector<bool> vis(MAXN, 0);
	queue<int> Q;
	Q.push(src), vis[src] = 1;
	int steps = 0;
	while (Q.size()) {
		int sz = Q.size();
		while (sz--) {
			int cur = Q.front();
			Q.pop();
			if (cur == tar)
				return steps;
			for (int i = 1; i < MAXN; i *= 10) {
				for (int d = !(i * 10 < MAXN); d < 10; d++) {
					int nxt = cur - (cur / i % 10 * i) + d * i;
					if (!comp[nxt] && !vis[nxt]) {
						Q.push(nxt), vis[nxt] = 1;
					}
				}
			}
		}
		steps++;
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	comp[0] = comp[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		if (!comp[i]) {
			for (int j = i * i; j < MAXN; j += i) {
				comp[j] = 1;
			}
		}
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &src, &tar);
		int ans = BFS();
		if (ans != -1)
			printf("%d\n", ans);
		else
			printf("Impossible\n");
	}
	return 0;
}
