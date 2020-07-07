/*
 * 321. Dream Coins.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct coin {
	int x, y, z, v;

	const bool operator <(const coin &a) const {
		return z < a.z;
	}
};

int n;
coin all[1005];
long long dp[1005];

bool valid(int a, int b) {
	int dx = abs(all[a].x - all[b].x);
	int dy = abs(all[a].y - all[b].y);
	int dz = abs(all[a].z - all[b].z);
	return (dx + dy <= dz);
}

long long solve(int idx) {
	if (idx == n - 1)
		return all[idx].v;
	long long &ret = dp[idx];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = idx + 1; i < n; i++)
		if (valid(idx, i))
			ret = max(ret, solve(i));
	ret += all[idx].v;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t, tc = 0;
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof dp);
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> all[i].x >> all[i].y >> all[i].z >> all[i].v;
		sort(all, all + n);
		long long ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, solve(i));
		cout << "Case " << ++tc << ": " << ans << endl;
	}
	return 0;
}
