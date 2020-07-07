/*
 * 469B. Chat Online.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int p, q;
vector<pair<int, int>> Z, X;

bool check(int t) {
	for (int i = 0; i < p; i++)
		for (int j = 0; j < q; j++)
			if (X[j].second + t >= Z[i].first && X[j].first + t <= Z[i].second)
				return true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int l, r;
	cin >> p >> q >> l >> r;
	Z.resize(p), X.resize(q);
	for (int i = 0; i < p; i++)
		cin >> Z[i].first >> Z[i].second;
	for (int i = 0; i < q; i++)
		cin >> X[i].first >> X[i].second;
	int ans = 0;
	for (int i = l; i <= r; i++)
		ans += check(i);
	cout << ans << endl;
	return 0;
}
