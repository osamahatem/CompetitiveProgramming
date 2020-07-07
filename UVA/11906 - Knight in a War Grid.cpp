/*
 * 11906 - Knight in a War Grid.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[105][105], inv[105][105];

bool valid(int r, int c, int R, int C) {
	return r >= 0 && r < R && c >= 0 && c < C && !inv[r][c];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(inv, 0, sizeof inv);
		memset(vis, 0, sizeof vis);
		int R, C, M, N, W;
		scanf("%d%d%d%d%d", &R, &C, &M, &N, &W);
		int dr[] = { M, M, -M, -M, N, N, -N, -N }, dc[] = { N, -N, N, -N, M, -M,
				M, -M };
		while (W--) {
			int r, c;
			scanf("%d%d", &r, &c);
			inv[r][c] = 1;
		}
		queue<int> Q;
		Q.push(0);
		Q.push(0);
		vis[0][0] = 1;
		while (Q.size()) {
			int r = Q.front();
			Q.pop();
			int c = Q.front();
			Q.pop();
			for (int i = 0; i < 8; i++) {
				int rr = r + dr[i], cc = c + dc[i];
				if (valid(rr, cc, R, C) && !vis[rr][cc]) {
					Q.push(rr);
					Q.push(cc);
					vis[rr][cc] = 1;
				}
			}
		}
		int ans[2] = { 0, 0 };
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (vis[i][j]) {
					set<pair<int, int>> dis;
					for (int d = 0; d < 8; d++) {
						int rr = i + dr[d], cc = j + dc[d];
						if (valid(rr, cc, R, C) && vis[rr][cc])
							dis.insert(make_pair(rr, cc));
					}
					ans[(int) dis.size() & 1]++;
				}
		printf("Case %d: %d %d\n", t, ans[0], ans[1]);
	}
	return 0;
}
