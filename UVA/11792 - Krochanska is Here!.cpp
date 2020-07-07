/*
 * 11792 - Krochanska is Here!.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<int> adj[10001];
int vis[10001], cnt[10001], id;

int BFS(int src) {
	int steps = 0, ans = 0;
	queue<int> Q;
	Q.push(src), vis[src] = ++id;
	while (Q.size()) {
		int sz = Q.size();
		while (sz--) {
			int cur = Q.front();
			Q.pop();
			if (cnt[cur] > 1)
				ans += steps;
			for (int i = 0; i < (int) adj[cur].size(); i++) {
				int to = adj[cur][i];
				if (vis[to] != id)
					Q.push(to), vis[to] = id;
			}
		}
		steps++;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(cnt, 0, sizeof cnt);
		int n, l;
		scanf("%d%d", &n, &l);
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		while (l--) {
			int last, x;
			scanf("%d", &last);
			cnt[last]++;
			while (scanf("%d", &x), x) {
				adj[x].push_back(last);
				adj[last].push_back(x);
				last = x;
				cnt[x]++;
			}
		}
		int mini = 1e9, st = -1;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] < 2)
				continue;
			int temp = BFS(i);
			if (temp < mini)
				mini = temp, st = i;
		}
		printf("Krochanska is in: %d\n", st);
	}
	return 0;
}
