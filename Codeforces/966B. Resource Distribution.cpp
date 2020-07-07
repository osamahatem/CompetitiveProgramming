/*
 * 966B. Resource Distribution.cpp
 *
 *  Created on: Apr 29, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;

int n, x1, x2;
pair<int, int> c[MAXN];
pair<long long, int> max_cum[MAXN];

int check(int idx, int x1, int x2) {
	int need = (x1 + c[idx].first - 1) / c[idx].first;
	if (idx + need < n && max_cum[idx + need].first >= x2)
		return max_cum[idx + need].second;
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> x1 >> x2;
	for (int i = 0; i < n; i++) {
		cin >> c[i].first;
		c[i].second = i;
	}

	sort(c, c + n);
	max_cum[n] = make_pair(0, n);
	for (int i = n - 1; ~i; i--)
		max_cum[i] = max(make_pair(1ll * c[i].first * (n - i), i),
				max_cum[i + 1]);

	for (int i = 0; i < n; i++) {
		int ans = check(i, x1, x2);
		if (ans != -1) {
			cout << "Yes" << endl;
			cout << ans - i << " " << n - ans << endl;
			for (int j = i; j < ans; j++)
				cout << c[j].second + 1 << " \n"[j + 1 == ans];
			for (int j = ans; j < n; j++)
				cout << c[j].second + 1 << " \n"[j + 1 == n];
			return 0;
		}

		ans = check(i, x2, x1);
		if (ans != -1) {
			cout << "Yes" << endl;
			cout << n - ans << " " << ans - i << endl;
			for (int j = ans; j < n; j++)
				cout << c[j].second + 1 << " \n"[j + 1 == n];
			for (int j = i; j < ans; j++)
				cout << c[j].second + 1 << " \n"[j + 1 == ans];
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
