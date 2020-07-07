/*
 * 529E. The Art of Dealing with ATM.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

set<int> all[21];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, arr[5005], q;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i <= k; i++)
		for (int j = 0; j < n; j++)
			all[i].insert(arr[j] * i);
	cin >> q;
	while (q--) {
		int x, ans = -1;
		cin >> x;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= k; j++)
				for (int l = 0; l <= k - j; l++)
					if (all[l].count(x - arr[i] * j)) {
						if (ans == -1)
							ans = l + j;
						else
							ans = min(ans, l + j);
					}
		cout << ans << endl;
	}
	return 0;
}
