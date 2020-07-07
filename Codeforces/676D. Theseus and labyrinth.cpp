/*
 * 676D. Theseus and labyrinth.cpp
 *
 *  Created on: May 25, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int x, y, r;
};

int n, m, xt, yt, xm, ym;
bool grid[1000][1000][4], dict[256][4], vis[1000][1000][4];
char temp[1001];
int dr[] = { -1, 0, 1, 0 }, dc[] = { 0, 1, 0, -1 };

void rotate(int arr[]) {
	int temp = arr[3];
	for (int i = 3; i; i--)
		arr[i] = arr[i - 1];
	arr[0] = temp;
}

int solve() {
	queue<node> Q;
	Q.push(node { xt, yt, 0 });
	vis[xt][yt][0] = 1;
	int dist = 0;
	while (Q.size()) {
		int sz = Q.size();
		while (sz--) {
			int x = Q.front().x, y = Q.front().y, r = Q.front().r;
			Q.pop();
			if (x == xm && y == ym)
				return dist;
			int rr = (r + 1) % 4;
			if (!vis[x][y][rr])
				Q.push(node { x, y, rr }), vis[x][y][rr] = 1;
			for (int i = 0; i < 4; i++) {
				int xx = x + dr[i], yy = y + dc[i];
				if (xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy][r]) {
					int arr1[4], arr2[4];
					for (int j = 0; j < 4; j++)
						arr1[j] = grid[x][y][j], arr2[j] = grid[xx][yy][j];
					for (int j = 0; j < r; j++)
						rotate(arr1), rotate(arr2);
					if (arr1[i] && arr2[(i + 2) % 4])
						Q.push(node { xx, yy, r }), vis[xx][yy][r] = 1;
				}
			}
		}
		dist++;
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	dict['+'][0] = dict['|'][0] = dict['^'][0] = dict['L'][0] = dict['R'][0] =
			dict['D'][0] = 1;
	dict['+'][1] = dict['-'][1] = dict['>'][1] = dict['L'][1] = dict['U'][1] =
			dict['D'][1] = 1;
	dict['+'][2] = dict['|'][2] = dict['v'][2] = dict['L'][2] = dict['U'][2] =
			dict['R'][2] = 1;
	dict['+'][3] = dict['-'][3] = dict['<'][3] = dict['U'][3] = dict['R'][3] =
			dict['D'][3] = 1;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", temp);
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 4; k++)
				grid[i][j][k] = dict[(int) temp[j]][k];
	}
	scanf("%d%d%d%d", &xt, &yt, &xm, &ym);
	xt--, yt--, xm--, ym--;
	printf("%d\n", solve());
	return 0;
}
