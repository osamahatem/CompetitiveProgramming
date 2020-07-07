/*
 * 11101 - Mall Mania.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int N = 2001;

int grid[N][N], vis[N][N], id;
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int p;
	while (scanf("%d", &p), p) {
		id++;
		int r, c, steps = 0, ans = -1;
		queue<int> Q;
		while (p--) {
			scanf("%d%d", &r, &c);
			Q.push(r);
			Q.push(c);
			vis[r][c] = id;
		}
		scanf("%d", &p);
		while (p--) {
			scanf("%d%d", &r, &c);
			grid[r][c] = id;
		}
		while (Q.size() && ans == -1) {
			int sz = Q.size();
			while (sz -= 2, sz + 2 && ans == -1) {
				r = Q.front();
				Q.pop();
				c = Q.front();
				Q.pop();
				if (grid[r][c] == id)
					ans = steps;
				for (int i = 0; i < 4; i++) {
					int rr = r + dr[i], cc = c + dc[i];
					if (rr >= 0 && rr < N && cc >= 0 && cc < N
							&& vis[rr][cc] != id) {
						Q.push(rr);
						Q.push(cc);
						vis[rr][cc] = id;
					}
				}
			}
			steps++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
