/*
 * 540B. School Marks.cpp
 *
 *  Created on: Apr 30, 2015
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

	int n, k, p, x, y, sum = 0, arr[1005];
	cin >> n >> k >> p >> x >> y;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + k);
	vector<int> ans;
	int tar = n / 2;
	int idx = lower_bound(arr, arr + k, y) - arr;
	if (idx == k) {
		sum += y;
		ans.push_back(y);
		k++;
	}
	for (int i = 0; i < n - k; i++) {
		if (idx < tar)
			sum++, idx++, ans.push_back(1);
		else
			sum += y, ans.push_back(y);
	}
	if (sum > x || idx > tar) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
