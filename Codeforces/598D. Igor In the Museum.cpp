/*
 * 598D. Igor In the Museum.cpp
 *
 *  Created on: Nov 13, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 }, N, M, ans[1005][1005], cnt;
bool vis[1005][1005];
char grid[1005][1005];
vector<pair<int, int>> temp;

bool valid(int r, int c) {
	return !vis[r][c] && grid[r][c] != '*';
}

void dfs(int r, int c) {
	vis[r][c] = 1, temp.push_back(make_pair(r, c));
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (valid(nr, nc))
			dfs(nr, nc);
		else if (!vis[nr][nc])
			cnt++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int k;
	scanf("%d%d%d", &N, &M, &k);
	for (int i = 0; i < N; i++)
		scanf("%s", grid[i]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (!valid(i, j))
				continue;
			cnt = 0, temp.clear();
			dfs(i, j);
			for (int c = 0; c < (int) temp.size(); c++)
				ans[temp[c].first][temp[c].second] = cnt;
		}
	while (k--) {
		scanf("%d%d", &N, &M);
		N--, M--;
		printf("%d\n", ans[N][M]);
	}
	return 0;
}
