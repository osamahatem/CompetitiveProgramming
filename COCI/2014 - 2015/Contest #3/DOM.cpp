/*
 * DOM.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int nxt[100005];
bool vis[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(nxt, -1, sizeof nxt);
	memset(vis, 0, sizeof vis);
	int n, m, p, a, b, ans = 0;
	cin >> n >> m >> p;
	while (n--) {
		cin >> a >> b;
		nxt[b] = (nxt[b] == -1 ? a : nxt[b]);
	}
	while (nxt[p] != -1) {
		if (vis[p]) {
			cout << "-1\n";
			return 0;
		}
		vis[p] = 1;
		p = nxt[p];
		ans++;
	}
	cout << ans << endl;
	return 0;
}
