/*
 * C. Go, Gopher!.cpp
 *
 *  Created on: Apr 7, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int T, A;
bool vis[5][75];

bool check(int r, int c) {
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (!vis[r + i][c + j])
				return false;
	return true;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		memset(vis, 0, sizeof vis);

		cin >> A;

		int r, c, cnt = 0;
		for (int i = 0; i < A; i += 9) {
			while (!check(2, i / 3 + 2)) {
				cout << 2 << " " << i / 3 + 2 << endl;
				cin >> r >> c;

				if (!r && !c)
					break;

				if (r == -1 && c == -1)
					return 0;

				vis[r][c] = 1;
				cnt++;
			}
		}
		cerr << cnt << endl;
	}
	return 0;
}
