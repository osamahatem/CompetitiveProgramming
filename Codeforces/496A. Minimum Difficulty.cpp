/*
 * 496A. Minimum Difficulty.cpp
 *
 *  Created on: Dec 17, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, maxi = 0, arr[105];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 1; i < n; i++)
		maxi = max(maxi, arr[i] - arr[i - 1]);
	int ans = 1000;
	for (int i = 1; i + 1 < n; i++)
		ans = min(ans, max(maxi, arr[i + 1] - arr[i - 1]));
	cout << ans << endl;
	return 0;
}
