/*
 * L. Least Common Ancestor.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 15e4 + 5;

int n, l1[MAXN], r1[MAXN], l2[MAXN], r2[MAXN], la[MAXN], ra[MAXN];

bool solve(int x, int y) {
	if (l1[x] == 0 || l2[y] == 0)
		return l1[x] == 0 && l2[y] == 0;

	int idx = n;
	la[idx] = ++n;
	bool comp = solve(l1[x], l2[y]);
	ra[idx] = ++n;
	return comp ? solve(r1[x], r2[y]) : false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> n, n) {
		for (int i = 1; i <= n; i++)
			cin >> l1[i] >> r1[i];
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> l2[i] >> r2[i];

		memset(la, 0, sizeof la), memset(ra, 0, sizeof ra), n = 1;
		solve(1, 1);

		cout << n << endl;
		for (int i = 1; i <= n; i++)
			cout << la[i] << " " << ra[i] << endl;
	}
	return 0;
}
