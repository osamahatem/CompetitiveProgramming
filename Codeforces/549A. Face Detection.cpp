/*
 * 549A. Face Detection.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char grid[55][55];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			string temp = "";
			temp += grid[i][j];
			temp += grid[i + 1][j];
			temp += grid[i][j + 1];
			temp += grid[i + 1][j + 1];
			sort(temp.begin(), temp.end());
			if (temp == "acef")
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
