/*
 * 6820 - Wet Tiles.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int x, y, dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
bool inv[1005][1005], vis[1005][1005];

bool valid(int xx, int yy) {
	return (xx && xx <= x && yy && yy <= y);
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	int t, l, w;
	while (scanf("%d", &x), x != -1) {
		memset(inv, 0, sizeof inv);
		memset(vis, 0, sizeof vis);
		scanf("%d%d%d%d", &y, &t, &l, &w);
		int xx, yy, x2, y2;
		queue<int> Q;
		for (int i = 0; i < l; i++) {
			scanf("%d%d", &xx, &yy);
			Q.push(xx);
			Q.push(yy);
			vis[xx][yy] = 1;
		}
		for (int i = 0; i < w; i++) {
			scanf("%d%d%d%d", &xx, &yy, &x2, &y2);
			if (xx == x2 || yy == y2) {
				if (yy > y2)
					swap(yy, y2);
				if (xx > x2)
					swap(xx, x2);
				for (int i = xx; i <= x2; i++)
					for (int j = yy; j <= y2; j++)
						inv[i][j] = 1;
			} else {
				int dx = (x2 - xx) / abs(x2 - xx), dy = (y2 - yy)
						/ abs(y2 - yy);
				int dst = abs(x2 - xx) + 1;
				for (int i = 0; i < dst; i++)
					inv[xx + dx * i][yy + dy * i] = 1;
			}
		}
		int ans = 0;
		while (t-- && Q.size()) {
			int sz = (int) Q.size() / 2;
			while (sz--) {
				xx = Q.front();
				Q.pop();
				yy = Q.front();
				Q.pop();
				ans++;
				for (int i = 0; i < 4; i++) {
					int nx = xx + dx[i], ny = yy + dy[i];
					if (valid(nx, ny) && !vis[nx][ny] && !inv[nx][ny]) {
						Q.push(nx);
						Q.push(ny);
						vis[nx][ny] = 1;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
