/*
 * 12160 - Unlock the Lock.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int L, U, R, T, arr[10], vis[10000], id;

int BFS() {
	int steps = 0;
	queue<int> Q;
	Q.push(L), vis[L] = ++id;
	while (Q.size()) {
		int sz = Q.size();
		while (sz--) {
			int cur = Q.front();
			Q.pop();
			if (cur == U)
				return steps;
			for (int i = 0; i < R; i++) {
				int nxt = (cur + arr[i]) % 10000;
				if (vis[nxt] != id)
					Q.push(nxt), vis[nxt] = id;
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

	while (scanf("%d%d%d", &L, &U, &R), L || U || R) {
		for (int i = 0; i < R; i++)
			scanf("%d", &arr[i]);
		int ans = BFS();
		printf("Case %d: ", ++T);
		if (ans == -1)
			printf("Permanently Locked\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
