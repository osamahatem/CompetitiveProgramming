/*
 * 300B. Coach.cpp
 *
 *  Created on: Nov 30, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<int> adj[50], temp;
bool vis[50];

void DFS(int n) {
	vis[n] = 1;
	temp.push_back(n);
	for (int i = 0; i < (int) adj[n].size(); i++)
		if (!vis[adj[n][i]])
			DFS(adj[n][i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<vector<int> > ans;
	vector<int> ones;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			temp.clear();
			DFS(i);
			if (temp.size() > 3) {
				cout << "-1\n";
				return 0;
			}
			if (temp.size() == 1)
				ones.push_back(temp[0]);
			else
				ans.push_back(temp);
		}
	}
	int idx = 0;
	for (int i = 0; i < (int) ans.size(); i++) {
		while (ans[i].size() < 3 && idx < ones.size())
			ans[i].push_back(ones[idx++]);
		if (ans[i].size() < 3) {
			cout << "-1\n";
			return 0;
		}
	}
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
	while (idx < (int) ones.size())
		cout << ones[idx++] << " " << ones[idx++] << " " << ones[idx++] << endl;
	return 0;
}
