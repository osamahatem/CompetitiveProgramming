/*
 * 980C. Posterized.cpp
 *
 *  Created on: May 8, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/59350
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, k, vis[256];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	set<int> S;
	for (int i = 0; i < 256; i++)
		S.insert(i), vis[i] = -1;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (vis[x] == -1) {
			int val = *S.lower_bound(max(x - k + 1, 0));
			for (int j = val; j <= x; j++)
				vis[j] = val, S.erase(j);
			S.insert(val);
		}
		if (i)
			cout << " ";
		cout << vis[x];
	}
	cout << endl;
	return 0;
}
