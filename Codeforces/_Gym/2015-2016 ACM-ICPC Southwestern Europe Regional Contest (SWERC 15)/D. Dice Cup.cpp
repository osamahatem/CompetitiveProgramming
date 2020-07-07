/*
 * D. Dice Cup.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[44];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cnt[i + j]++;
	int maxi = 0;
	for (int i = 1; i <= n + m; i++)
		maxi = max(maxi, cnt[i]);
	for (int i = 1; i <= n + m; i++)
		if (cnt[i] == maxi)
			cout << i << endl;
	return 0;
}
