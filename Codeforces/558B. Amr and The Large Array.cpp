/*
 * 558B. Amr and The Large Array.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXV = 1e6 + 5;

int st[MAXV], cnt[MAXV];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, v, maxi = 0, l = 0, r = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v;
		if (!cnt[v])
			st[v] = i;
		cnt[v]++;
		if (cnt[v] > maxi)
			maxi = cnt[v], l = st[v], r = i;
		else if (cnt[v] == maxi && i - st[v] < r - l)
			l = st[v], r = i;
	}
	cout << l << " " << r << endl;
	return 0;
}
