/*
 * 624B. Making a String.cpp
 *
 *  Created on: Mar 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, cnt[26];
long long ans = 0;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cnt[i];
	sort(cnt, cnt + n, greater<int>());
	int maxi = cnt[0] + 1;
	for (int i = 0; i < n; i++) {
		maxi = min(maxi - 1, cnt[i]);
		maxi = max(maxi, 0);
		ans += maxi;
	}
	cout << ans << endl;
	return 0;
}
