/*
 * 389C. Fox and Box Accumulation.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, arr[105];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int cnt = 0, ans = 0;
	while (cnt < n) {
		int sz = 0;
		for (int i = 0; i < n; i++)
			if (!vis[i] && arr[i] >= sz)
				vis[i] = 1, sz++, cnt++;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
