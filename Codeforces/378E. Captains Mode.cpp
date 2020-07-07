/*
 * 378E. Captains Mode.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, arr[105], team[20], dp[1 << 20];
char act[20];
bool vis[1 << 20];

int solve(int idx, int mask) {
	if (idx == m)
		return 0;
	if (vis[mask])
		return dp[mask];
	vis[mask] = 1;
	int ret = -(1 << 30);
	for (int i = 0; i < m; i++) {
		if (mask & (1 << i))
			continue;
		int temp = (act[idx] == 'p' ? arr[i] : 0);
		int tempp = solve(idx + 1, mask | (1 << i));
		if (team[idx] != team[idx + 1])
			temp -= tempp;
		else
			temp += tempp;
		ret = max(ret, temp);
	}
	return dp[mask] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n, greater<int>());
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> act[i] >> team[i];
	cout << solve(0, 0) * (team[0] == 2 ? -1 : 1) << endl;
	return 0;
}
