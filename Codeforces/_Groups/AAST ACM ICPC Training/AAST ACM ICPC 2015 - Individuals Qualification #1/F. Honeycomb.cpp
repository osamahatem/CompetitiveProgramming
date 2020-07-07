/*
 * F. Honeycomb.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[305][305];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("honeycomb.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(vis, 0, sizeof vis);
		int R, C, r1, c1, r2, c2, ans = -1;
		cin >> R >> C >> r1 >> c1 >> r2 >> c2;
		queue<int> Q;
		Q.push(r1);
		Q.push(c1);
		vis[r1][c1] = 1;
		while (Q.size()) {
			ans++;
			int sz = Q.size() / 2;
			while (sz--) {
				int r = Q.front();
				Q.pop();
				int c = Q.front();
				Q.pop();
				if (r == r2 && c == c2) {
					while (Q.size())
						Q.pop();
					break;
				}
				for (int i = -1; i < 2; i++)
					for (int j = -1; j < 2; j++) {
						if ((!i && !j) || (c % 2 && j && i == 1)
								|| (c % 2 == 0 && j && i == -1))
							continue;
						int nr = r + i, nc = c + j;
						if (nr > R || nr < 1 || nc > C || nc < 1 || vis[nr][nc])
							continue;
						Q.push(nr);
						Q.push(nc);
						vis[nr][nc] = 1;
					}
			}
		}
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
