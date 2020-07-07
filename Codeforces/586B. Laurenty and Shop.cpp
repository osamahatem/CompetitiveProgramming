/*
 * 586B. Laurenty and Shop.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int a[2][55], b[55];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, ans = 1 << 28;
	cin >> n;
	for (int i = 0; i < 2; i++)
		for (int j = 1; j < n; j++) {
			cin >> a[i][j];
			a[i][j] += a[i][j - 1];
		}
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			int temp = b[i] + b[j];
			temp += a[1][n - 1] - a[1][i] + a[0][i];
			temp += a[0][j] + a[1][n - 1] - a[1][j];
			ans = min(ans, temp);
		}
	cout << ans << endl;
	return 0;
}
