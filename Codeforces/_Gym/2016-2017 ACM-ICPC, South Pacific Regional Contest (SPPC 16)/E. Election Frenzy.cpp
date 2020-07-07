/*
 * E. Election Frenzy.cpp
 *
 *  Created on: Oct 12, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int n;
vector<int> adj[MAXN];
bool t[MAXN], ans[MAXN];
set<int> vis;

int DFS(int idx, bool a) {
	vis.erase(idx);
	ans[idx] = a;
	int cnt = 1;
	if (t[idx]) {
		for (auto ch : adj[idx])
			if (vis.count(ch))
				cnt += DFS(ch, !a);
	} else {
		auto it = vis.begin();
		for (int i = 0; i < (int) adj[idx].size(); i++) {
			int ch = adj[idx][i];
			if (it == vis.end())
				break;
			int v = *it;
			if (ch <= v) {
				if (ch == v)
					it = vis.upper_bound(v);
				continue;
			}
			cnt += DFS(v, !a);
			it = vis.upper_bound(v);
			i--;
		}
		while (it != vis.end()) {
			int v = *it;
			cnt += DFS(*it, !a);
			it = vis.upper_bound(v);
		}
	}
	return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		vis.insert(i);
		char in[5];
		int x;
		scanf("%s%d", in, &x);
		t[i] = (in[0] == 'C');
		while (x--) {
			int y;
			scanf("%d", &y);
			adj[i].push_back(y);
		}
		sort(adj[i].begin(), adj[i].end());
	}
	bool flag = 1;
	for (int i = 1; i <= n; i++)
		if (vis.count(i))
			flag &= (DFS(i, 0) != 1);
	if (!flag) {
		printf("Impossible\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		printf("%c", ans[i] ? 'V' : 'S');
	printf("\n");
	return 0;
}
