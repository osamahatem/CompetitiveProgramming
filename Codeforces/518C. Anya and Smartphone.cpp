/*
 * 518C. Anya and Smartphone.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, k, pos[MAXN], icon[MAXN];
	long long ans = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> icon[i];
		icon[i]--;
		pos[icon[i]] = i;
	}
	while (m--) {
		cin >> n;
		n--;
		ans += pos[n] / k + 1;
		if (pos[n] > 0) {
			int prv = icon[pos[n] - 1];
			icon[pos[n]] = prv;
			icon[pos[n] - 1] = n;
			pos[n]--;
			pos[prv]++;
		}
	}
	cout << ans << endl;
	return 0;
}
