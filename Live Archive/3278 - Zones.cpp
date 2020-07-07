/*
 * 3278 - Zones.cpp
 *
 *  Created on: Jan 8, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int tow[22];
pair<int, int> common[11];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, req, q, t = 0;
	while (cin >> n >> req, n) {
		for (int i = 0; i < n; i++)
			cin >> tow[i];

		cin >> q;
		for (int i = 0; i < q; i++) {
			int x, y, m = 0;
			cin >> x;
			while (x--) {
				cin >> y;
				m |= 1 << (n - y);
			}
			cin >> x;
			common[i] = make_pair(m, x);
			for (int j = 0; j < n; j++)
				if (m & (1 << (n - j - 1)))
					tow[j] -= x;
		}

		int ans = 0, m = 0;
		for (int i = 1; i < (1 << n); i++) {
			if (__builtin_popcount(i) != req)
				continue;
			int temp = 0;
			for (int j = 0; j < n; j++)
				if (i & (1 << (n - j - 1)))
					temp += tow[j];
			for (int j = 0; j < q; j++)
				if (i & common[j].first)
					temp += common[j].second;
			if (temp >= ans)
				ans = temp, m = i;
		}

		cout << "Case Number  " << ++t << endl;
		cout << "Number of Customers: " << ans << endl;
		cout << "Locations recommended:";
		for (int i = 0; i < n; i++)
			if (m & (1 << (n - i - 1)))
				cout << " " << i + 1;
		cout << endl << endl;
	}
	return 0;
}
