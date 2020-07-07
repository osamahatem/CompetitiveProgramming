/*
 * 1.Marathon.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int solve(pair<int, int> a, pair<int, int> b) {
	int dx = abs(a.first - b.first);
	int dy = abs(a.second - b.second);
	return dx + dy;
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
//#endif

	int n, dist = 0;
	pair<int, int> all[100005];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> all[i].first >> all[i].second;
		if (i)
			dist += solve(all[i], all[i - 1]);
	}
	int ans = dist;
	for (int i = 1; i + 1 < n; i++) {
		int temp = dist;
		temp -= solve(all[i], all[i - 1]);
		temp -= solve(all[i], all[i + 1]);
		temp += solve(all[i - 1], all[i + 1]);
		ans = min(ans, temp);
	}
	cout << ans << endl;
	return 0;
}
