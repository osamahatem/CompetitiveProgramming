/*
 * 242D. Dispute.cpp
 *
 *  Created on: Dec 31, 2017
 *      Author: Osama Hatem
 */
 
/*
Press all the buttons at first, then use a BFS to undo that on all losing nodes.
There is always a solution, because a node that is losing can be converted by
undoing its button press. Each node will be pushed at most once in the queue.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, arr[MAXN], cnt[MAXN];
vector<int> adj[MAXN];
bool used[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
		cnt[u]++, cnt[v]++;
	}
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (++cnt[i] == arr[i])
			Q.push(i);
		used[i] = true;
	}
	while (Q.size()) {
		int cur = Q.front();
		Q.pop();
		if (cnt[cur] != arr[cur])
			continue;
		used[cur] = false, cnt[cur]--;
		for (auto ch : adj[cur])
			if (--cnt[ch] == arr[ch])
				Q.push(ch);
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++)
		if (used[i])
			ans.push_back(i);
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
