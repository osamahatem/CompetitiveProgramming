/*
 * 140D. New Year Contest.cpp
 *
 *  Created on: Apr 23, 2015
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

	int n, t = 10, arr[105], pen = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n && t + arr[i] <= 720; i++) {
		ans++;
		t += arr[i];
		pen += max(t - 360, 0);
	}
	cout << ans << " " << pen << endl;
	return 0;
}
