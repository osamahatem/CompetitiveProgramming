/*
 * 405A. Gravity Flip.cpp
 *
 *  Created on: Jul 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, arr[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << arr[i];
	}
	cout << endl;
	return 0;
}
