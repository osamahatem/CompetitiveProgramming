/*
 * 347A. Difference Row.cpp
 *
 *  Created on: Aug 24, 2015
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

	int n, arr[105];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n, greater<int>());
	reverse(arr + 1, arr + n - 1);
	for (int i = 0; i < n; i++)
		cout << (i ? " " : "") << arr[i];
	cout << endl;
	return 0;
}
