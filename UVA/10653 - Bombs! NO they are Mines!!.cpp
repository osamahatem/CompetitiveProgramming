/*
 * 10653 - Bombs! NO they are Mines!!.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C, vis[1005][1005], id;
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };

int BFS(int sr, int sc, int er, int ec) {
	int steps = 0;
	queue<int> Q;
	Q.push(sr);
	Q.push(sc);
	vis[sr][sc] = id;
	while (Q.size()) {
		int sz = Q.size();
		while (sz) {
			int r = Q.front();
			Q.pop();
			int c = Q.front();
			Q.pop();
			sz -= 2;
			if (r == er && c == ec)
				return steps;
			for (int i = 0; i < 4; i++) {
				int rr = r + dr[i], cc = c + dc[i];
				if (rr >= 0 && rr < R && cc >= 0 && cc < C
						&& vis[rr][cc] != id) {
					Q.push(rr);
					Q.push(cc);
					vis[rr][cc] = id;
				}
			}
		}
		steps++;
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &R, &C), R) {
		id++;
		int rn, r, cnt, c;
		scanf("%d", &rn);
		while (rn--) {
			scanf("%d%d", &r, &cnt);
			while (cnt--) {
				scanf("%d", &c);
				vis[r][c] = id;
			}
		}
		int sr, sc, er, ec;
		scanf("%d%d%d%d", &sr, &sc, &er, &ec);
		printf("%d\n", BFS(sr, sc, er, ec));
	}
	return 0;
}
