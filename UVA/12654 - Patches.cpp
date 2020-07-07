/*
 * 12654 - Patches.cpp
 *
 *  Created on: Aug 16, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, c, t1, t2, arr[1005], memo[1005];

int solve(int i) {
	if (i >= n)
		return 0;
	int &ret = memo[i];
	if (ret != -1)
		return ret;
	ret = 1 << 30;
	int a = upper_bound(arr, arr + n, arr[i] + t1) - arr;
	ret = min(ret, t1 + solve(a));
	a = upper_bound(arr, arr + n, arr[i] + t2) - arr;
	ret = min(ret, t2 + solve(a));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (cin >> n >> c >> t1 >> t2) {
		memset(memo, -1, sizeof memo);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		cout << solve(0) << "\n";
	}
	return 0;
}
