/*
 * Tourist.cpp
 *
 *  Created on: Jul 7, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, k;
		long long v;
		cin >> n >> k >> v;
		vector<string> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int rem = n - ((v - 1) * k % n);
		cout << "Case #" << t << ":";
		for (int i = 0; i < k - rem; i++)
			cout << " " << arr[i];
		for (int i = n - rem, j = 0; j < k && i < n; j++, i++)
			cout << " " << arr[i];
		cout << endl;
	}
	return 0;
}
