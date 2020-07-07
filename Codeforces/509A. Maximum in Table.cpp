/*
 * 509A. Maximum in Table.cpp
 *
 *  Created on: Feb 2, 2015
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

	int n, arr[10][10];
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = ((!i || !j) ? 1 : arr[i - 1][j] + arr[i][j - 1]);
	cout << arr[n - 1][n - 1] << endl;
	return 0;
}
