/*
 * 583B. Robot's Task.cpp
 *
 *  Created on: Oct 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[1005];
bool vis[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int p = 1, ans = 0, cur = 0, d = 1, rem = n;
	while (rem) {
		if (p > n || p < 1) {
			d *= -1;
			p += d + d;
			ans++;
		}
		if (cur >= arr[p] && !vis[p])
			cur++, rem--, vis[p] = 1;
		p += d;
	}
	cout << ans << endl;
	return 0;
}
