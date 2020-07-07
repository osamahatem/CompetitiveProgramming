/*
 * 4128 - Steam Roller.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };
int R, C, sr, sc, er, ec, cost[105][105][4];
bool vis[105][105][5];

int solve() {
	memset(vis, 0, sizeof vis);
	set<tuple<int, int, int, int>> S;
	S.insert(make_tuple(0, sr, sc, 4));
	while (S.size()) {
		int cur = get<0>(*S.begin());
		int r = get<1>(*S.begin()), c = get<2>(*S.begin());
		int d = get<3>(*S.begin());
		S.erase(S.begin());
		if (vis[r][c][d])
			continue;
		vis[r][c][d] = 1;
		if (r == er && c == ec && d == 4)
			return cur;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i], e_cost = cost[r][c][i];
			if (nr < 1 || nr > R || nc < 1 || nc > C || !e_cost)
				continue;
			if (i == d || d == 4) {
				S.insert(make_tuple(cur + (e_cost << 1), nr, nc, 4));
				S.insert(make_tuple(cur + (e_cost << (d == 4)), nr, nc, i));
			}
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T = 0, x;
	while (cin >> R >> C >> sr >> sc >> er >> ec, R) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j < C; j++) {
				cin >> x;
				cost[i][j][1] = cost[i][j + 1][3] = x;
			}
			for (int j = 1; i != R && j <= C; j++) {
				cin >> x;
				cost[i][j][0] = cost[i + 1][j][2] = x;
			}
		}
		int ans = solve();
		cout << "Case " << ++T << ": ";
		if (ans == -1)
			cout << "Impossible";
		else
			cout << ans;
		cout << endl;
	}
	return 0;
}
