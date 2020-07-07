/*
 * A. Three Arrays.cpp
 *
 *  Created on: Apr 14, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e5 + 5;

int d, sz[3], arr[3][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> d >> sz[0] >> sz[1] >> sz[2]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < sz[i]; j++)
				cin >> arr[i][j];

		long long ans = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < sz[i]; j++) {
				long long temp = 1;
				for (int k = 0; k < i; k++)
					temp *= upper_bound(arr[k], arr[k] + sz[k], arr[i][j] + d)
							- lower_bound(arr[k], arr[k] + sz[k],
									arr[i][j] + 1);
				for (int k = i + 1; k < 3; k++)
					temp *= upper_bound(arr[k], arr[k] + sz[k], arr[i][j] + d)
							- lower_bound(arr[k], arr[k] + sz[k], arr[i][j]);
				ans += temp;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
