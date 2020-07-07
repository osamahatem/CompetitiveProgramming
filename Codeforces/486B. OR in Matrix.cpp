/*
 * 486B. OR in Matrix.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, mat[105][105], ans[105][105];
	memset(ans, -1, sizeof ans);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 0) {
				for (int k = 0; k < n; k++)
					ans[k][j] = 0;
				for (int k = 0; k < m; k++)
					ans[i][k] = 0;
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mat[i][j] == 1) {
				bool flag = 0;
				for (int k = 0; k < n; k++)
					if (ans[k][j] == -1 || ans[k][j] == 1)
						flag = 1, ans[k][j] = 1;
				for (int k = 0; k < m; k++)
					if (ans[i][k] == -1 || ans[i][k] == 1)
						flag = 1, ans[i][k] = 1;
				if (!flag) {
					cout << "NO\n";
					return 0;
				}
			}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j)
				cout << " ";
			cout << ans[i][j];
		}
		cout << "\n";
	}
	return 0;
}
