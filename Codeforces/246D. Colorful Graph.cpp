/*
 * 246D. Colorful Graph.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int colour[MAXN];
bool exist[MAXN];
set<int> ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, a, b, maxi = -1, maxID;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> colour[i], exist[colour[i]] = 1;
	while (m--) {
		cin >> a >> b;
		a = colour[a], b = colour[b];
		if (a != b)
			ans[a].insert(b), ans[b].insert(a);
	}
	for (int i = 1; i < MAXN; i++)
		if (exist[i] && (int) ans[i].size() > maxi)
			maxi = ans[i].size(), maxID = i;
	cout << maxID << endl;
	return 0;
}
