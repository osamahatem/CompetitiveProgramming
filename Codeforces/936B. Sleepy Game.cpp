/*
 * 936B. Sleepy Game.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Osama Hatem
 */
 
/*
The first thing to notice is that the second player moves aren't optimal, so we
can win if we can reach a leaf node on the second player's turn. If that can't
be achieved, a draw can be forced if there a reachable cycle from the source.
It's a loss otherwise. This can be easily checked, and the path built in case of
a win, using DFS and white-grey-black visited array.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, s;
vector<int> adj[MAXN], ans;
int vis[MAXN][2];

int solve(int idx, int turn) {
	vis[idx][turn] = 1;
	int ret = 0;
	if (adj[idx].empty())
		ret = turn;
	for (int i = 0; !(ret & 1) && i < (int) adj[idx].size(); i++) {
		int ch = adj[idx][i];
		if (vis[ch][0] == 1 || vis[ch][1] == 1)
			ret |= 2;
		if (vis[ch][1 - turn] == 0)
			ret |= solve(ch, 1 - turn);
	}
	vis[idx][turn] = 2;
	if (ret & 1)
		ans.push_back(idx);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		adj[i].resize(k);
		for (int j = 0; j < k; j++)
			cin >> adj[i][j];
	}
	cin >> s;
	int res = solve(s, 0);
	if (res & 1) {
		cout << "Win" << endl;
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < (int) ans.size(); i++) {
			if (i)
				cout << " ";
			cout << ans[i];
		}
		cout << endl;
	} else
		cout << (res & 2 ? "Draw" : "Lose") << endl;
	return 0;
}
