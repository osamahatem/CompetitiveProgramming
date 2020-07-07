/*
 * 216D. Spider's Web.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1005;

vector<int> dist[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		dist[i].resize(k);
		for (int j = 0; j < k; j++)
			cin >> dist[i][j];
		sort(dist[i].begin(), dist[i].end());
	}
	dist[0] = dist[n], dist[n + 1] = dist[1];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < (int) dist[i].size(); j++) {
			int left = lower_bound(dist[i - 1].begin(), dist[i - 1].end(),
					dist[i][j])
					- lower_bound(dist[i - 1].begin(), dist[i - 1].end(),
							dist[i][j - 1]);
			int right = lower_bound(dist[i + 1].begin(), dist[i + 1].end(),
					dist[i][j])
					- lower_bound(dist[i + 1].begin(), dist[i + 1].end(),
							dist[i][j - 1]);
			ans += left != right;
		}
	}
	cout << ans << endl;
	return 0;
}
