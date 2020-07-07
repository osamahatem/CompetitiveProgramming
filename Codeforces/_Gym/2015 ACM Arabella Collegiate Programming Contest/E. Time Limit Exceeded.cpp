/*
 * E. Time Limit Exceeded.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;

int arr[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		for (int s = 0, e = 0; s < n; s++) {
			while (e < n && arr[e] - arr[s] < 32)
				e++;
			ans += e - s - 1;
		}
		cout << ans << endl;
	}
	return 0;
}
