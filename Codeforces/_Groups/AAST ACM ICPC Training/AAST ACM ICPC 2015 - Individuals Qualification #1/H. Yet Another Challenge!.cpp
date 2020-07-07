/*
 * H. Yet Another Challenge!.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int head[55], nxt[105], to[105], id[105], last, cnt, inv;
bool vis[55];

void addEdge(int f, int t, int _id) {
	to[last] = t;
	id[last] = _id;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t, int _id) {
	addEdge(f, t, _id);
	addEdge(t, f, _id);
}

void dfs(int n) {
	vis[n] = 1, cnt++;
	for (int i = head[n]; i != -1; i = nxt[i])
		if (!vis[to[i]] && id[i] != inv)
			dfs(to[i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("yetanotherchallenge.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(head, -1, sizeof head), last = 0;
		int n, a, b, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			addBiEdge(a, b, i);
		}
		for (int i = 0; i < n; i++) {
			memset(vis, 0, sizeof vis), cnt = 0, inv = i;
			dfs(1);
			ans += cnt == n;
		}
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
