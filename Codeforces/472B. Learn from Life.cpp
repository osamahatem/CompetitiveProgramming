/*
 *  Learn from Life.cpp
 *
 *  Created on: Sep 28, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int> all(n);
	for (int i = 0; i < n; i++)
		cin >> all[i];
	sort(all.begin(), all.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < n; i += k)
		ans += 2 * all[i] - 2;
	cout << ans << "\n";
	return 0;
}
