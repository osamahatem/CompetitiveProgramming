/*
 * 913B. Christmas Spruce.cpp
 *
 *  Created on: Jan 8, 2018
 *      Author: Osama Hatem
 */

/*
http://codeforces.com/blog/entry/56992
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<int> adj[1005];

bool solve(int idx) {
	if (adj[idx].empty())
		return true;
	int cnt = 0;
	for (auto ch : adj[idx]) {
		if (!solve(ch))
			return false;
		if (adj[ch].empty())
			cnt++;
	}
	return cnt > 2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj[x].push_back(i);
	}
	cout << (solve(1) ? "Yes" : "No") << endl;
	return 0;
}
