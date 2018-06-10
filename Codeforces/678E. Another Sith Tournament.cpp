/*
 * 678E. Another Sith Tournament.cpp
 *
 *  Created on: Jun 9, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/45405
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
double p[20][20], dp[18][1 << 18];
bool vis[18][1 << 18];

double solve(int last, int mask, int cnt) {
	if (cnt == n)
		return 1.0;

	double &ret = dp[last][mask];
	if (vis[last][mask])
		return ret;

	vis[last][mask] = true;
	ret = 0.0;

	for (int i = 0; i < n; i++) {
		if (mask & (1 << i))
			continue;
		double temp = 0.0;
		if (last)
			temp += p[i][last] * solve(i, mask | (1 << i), cnt + 1);
		if (i)
			temp += p[last][i] * solve(last, mask | (1 << i), cnt + 1);
		ret = max(ret, temp);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> p[i][j];
	double ans = 0.0;
	for (int i = 0; i < n; i++)
		ans = max(ans, solve(i, 1 << i, 1));
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}
