/*
 * I. International Wedding.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[6][200];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

//	freopen("international.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		long long x, y, ans = 0;
		scanf("%d%lld%lld", &n, &x, &y);
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);
		vector<long long> a, b;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					a.push_back(1ll * arr[0][i] + arr[1][j] + arr[2][k]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					b.push_back(1ll * arr[3][i] + arr[4][j] + arr[5][k]);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < (int) a.size(); i++) {
			long long low = x - a[i], high = y - a[i];
			int idx_l = lower_bound(b.begin(), b.end(), low) - b.begin();
			int idx_h = upper_bound(b.begin(), b.end(), high) - b.begin() - 1;
			ans += idx_h - idx_l + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
