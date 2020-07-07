/*
 * 83C. Track.cpp
 *
 *  Created on: Aug 11, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
int n, m, k, sr, sc, er, ec, allMask, mask;
char grid[55][55];
bool vis[55][55];
int dist[55][55], pr[55][55], pc[55][55];

int countOnes(int x) {
	int ret = 0;
	while (x) {
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}

bool valid(int r, int c) {
	if (!(r >= 0 && r < n && c >= 0 && c < m))
		return false;
	if ((r == sr && c == sc) || (r == er && c == ec))
		return true;
	return (1 << (grid[r][c] - 'a')) & mask;
}

bool cmp(int r1, int c1, int r2, int c2) {
	if (grid[r1][c1] != grid[r2][c2])
		return grid[r1][c1] < grid[r2][c2];
	if (r1 == r2 && c1 == c2)
		return false;
	return cmp(pr[r1][c1], pc[r1][c1], pr[r2][c2], pc[r2][c2]);
}

string BFS() {
	memset(vis, 0, sizeof vis);
	dist[er][ec] = 0, vis[er][ec] = 1;
	queue<pair<int, int>> Q;
	Q.push(make_pair(er, ec));
	while (Q.size()) {
		int r = Q.front().first, c = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (!valid(nr, nc))
				continue;
			if (!vis[nr][nc]) {
				vis[nr][nc] = 1;
				pr[nr][nc] = r, pc[nr][nc] = c;
				dist[nr][nc] = dist[r][c] + 1;
				Q.push(make_pair(nr, nc));
			} else if (dist[nr][nc] == dist[r][c] + 1
					&& cmp(r, c, pr[nr][nc], pc[nr][nc]))
				pr[nr][nc] = r, pc[nr][nc] = c;
		}
	}
	if (!vis[sr][sc])
		return "ST";
	string ret;
	int r = pr[sr][sc], c = pc[sr][sc];
	while (r != er || c != ec) {
		ret += grid[r][c];
		int rr = pr[r][c], cc = pc[r][c];
		r = rr, c = cc;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		for (int j = 0; j < m; j++)
			if (grid[i][j] == 'S')
				sr = i, sc = j;
			else if (grid[i][j] == 'T')
				er = i, ec = j;
			else
				allMask |= 1 << (grid[i][j] - 'a');
	}
	string ans = "ST";
	for (mask = allMask; mask > 0; mask = allMask & (mask - 1)) {
		if (countOnes(mask) > k)
			continue;
		string temp = BFS();
		if (temp == "ST")
			continue;
		if (ans == "ST" || temp.size() < ans.size()
				|| (temp.size() == ans.size() && temp < ans))
			ans = temp;
	}
	string temp = BFS();
	if (temp != "ST"
			&& (ans == "ST" || temp.size() < ans.size()
					|| (temp.size() == ans.size() && temp < ans)))
		ans = temp;
	cout << (ans == "ST" ? "-1" : ans) << endl;
	return 0;
}
