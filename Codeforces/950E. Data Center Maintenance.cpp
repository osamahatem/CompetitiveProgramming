/*
 * 950E. Data Center Maintenance.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int N, M, H, h[MAXN];
vector<int> adj[MAXN];
int low[MAXN], idx[MAXN], vis[MAXN], comp[MAXN], cnt, _idx;
vector<vector<int>> scc;
stack<int> S;

void SCC(int n) {
	low[n] = idx[n] = ++_idx;
	S.push(n), vis[n] = 1;

	for (auto ch : adj[n]) {
		if (!vis[ch])
			SCC(ch);
		if (vis[ch] < 2)
			low[n] = min(low[n], low[ch]);
	}

	if (low[n] == idx[n]) {
		vector<int> temp;
		int cur;
		do {
			cur = S.top();
			S.pop(), vis[cur] = 2;
			temp.push_back(cur), comp[cur] = cnt;
		} while (cur != n);
		scc.push_back(temp), cnt++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> H;
	for (int i = 1; i <= N; i++)
		cin >> h[i];
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		if ((h[x] + 1) % H == h[y])
			adj[x].push_back(y);
		if ((h[y] + 1) % H == h[x])
			adj[y].push_back(x);
	}

	for (int i = 1; i <= N; i++)
		if (!vis[i])
			SCC(i);

	vector<int> ans;
	int sz = N + 1;
	for (auto grp : scc) {
		bool flag = true;
		for (auto node : grp)
			for (auto ch : adj[node])
				if (comp[node] != comp[ch])
					flag = false;
		if (flag && (int) grp.size() < sz)
			sz = grp.size(), ans = grp;
	}

	cout << sz << endl;
	for (int i = 0; i < sz; i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
