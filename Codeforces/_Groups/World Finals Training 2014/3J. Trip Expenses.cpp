/*
 * 3J. Trip Expenses.cpp
 *
 *  Created on: Jan 28, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("trip.in", "r", stdin);
	freopen("trip.out", "w", stdout);
//#endif

	int n, m, a, b, c;
	cin >> n >> m;
	long long dist[305][305];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dist[i][j] = 1ll << 60;
		dist[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dist[a][b] = dist[b][a] = min(dist[b][a], (long long) c * (m + 1) + 1);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			cnt += dist[i][j] % (m + 1);
	double ans = (double) cnt / (n * (n - 1) / 2);
	cout << fixed << setprecision(9) << ans << endl;
	return 0;
}
