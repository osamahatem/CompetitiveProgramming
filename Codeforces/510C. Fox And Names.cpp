/*
 * 510C. Fox And Names.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<int> adj[26];
int vis[26];
string ans;

bool solve(int n) {
	vis[n] = 2;
	for (int i = 0; i < (int) adj[n].size(); i++) {
		int t = adj[n][i];
		if (vis[t] == 2)
			return false;
		else if (!vis[t] && !solve(t))
			return false;
	}
	vis[n] = 1;
	ans += n + 'a';
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	string cur, last;
	cin >> n >> last;
	for (int i = 1; i < n; i++) {
		cin >> cur;
		int a = 0, b = 0;
		while (a < (int) last.size() && b < (int) cur.size()
				&& last[a] == cur[b])
			a++, b++;
		if (a < (int) last.size() && b < (int) cur.size()) {
			int x = last[a] - 'a', y = cur[b] - 'a';
			adj[x].push_back(y);
		} else if (b == (int) cur.size() && a < (int) last.size()) {
			cout << "Impossible" << endl;
			return 0;
		}
		last = cur;
	}
	for (int i = 0; i < 26; i++) {
		if (!vis[i] && !solve(i)) {
			cout << "Impossible" << endl;
			return 0;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
