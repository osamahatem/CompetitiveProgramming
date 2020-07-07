/*
 * RELINETS.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int INF = 1 << 30;

int n, m, T, u[20], v[20], c[20];
int head[15], nxt[40], to[40], last;
int indx[15], low[15], id, cnt;
bool vis[15];

void reset() {
	memset(head, -1, sizeof head), last = 0;
	memset(vis, 0, sizeof vis), id = 0, cnt = 0;
}

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

bool solve(int idx, int p) {
	vis[idx] = 1, indx[idx] = low[idx] = ++id, cnt++;
	for (int i = head[idx]; i != -1; i = nxt[i]) {
		if (!vis[to[i]]) {
			if (!solve(to[i], idx) || low[to[i]] > indx[idx])
				return false;
			low[idx] = min(low[idx], low[to[i]]);
		} else if (to[i] != p) {
			low[idx] = min(low[idx], indx[to[i]]);
		}
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &n, &m), n) {
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u[i], &v[i], &c[i]);
			u[i]--, v[i]--;
		}
		int ans = INF;
		for (int i = 1; i < (1 << m); i++) {
			reset();
			int cost = 0;
			for (int j = 0; j < m; j++)
				if (i & (1 << j))
					addEdge(u[j], v[j]), addEdge(v[j], u[j]), cost += c[j];
			if (cost < ans && solve(0, -1) && cnt == n)
				ans = cost;
		}
		if (ans < INF)
			printf("The minimal cost for test case %d is %d.\n", ++T, ans);
		else
			printf("There is no reliable net possible for test case %d.\n",
					++T);
	}
	return 0;
}
