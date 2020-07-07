/*
 * 624 - CD.cpp
 *
 *  Created on: Sep 28, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, t, d[20];
	while (cin >> n >> t) {
		for (int i = 0; i < t; i++)
			cin >> d[i];
		int ans = 0, mask = 0;
		for (int i = 0; i < (1 << t); i++) {
			int cur = 0;
			for (int b = 0; b < t; b++)
				if (i & (1 << b))
					cur += d[b];
			if (cur <= n && cur > ans)
				ans = cur, mask = i;
		}
		for (int i = 0; i < t; i++)
			if (mask & (1 << i))
				cout << d[i] << " ";
		cout << "sum:" << ans << "\n";
	}
	return 0;
}
