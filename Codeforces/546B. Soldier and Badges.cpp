/*
 * 546B. Soldier and Badges.cpp
 *
 *  Created on: May 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[6005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, arr[3005];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[arr[i]]) {
			arr[i]++, ans++;
			i--;
		} else
			vis[arr[i]] = 1;
	}
	cout << ans << endl;
	return 0;
}
