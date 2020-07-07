/*
 * F. Evacuation.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXP = 105;
const int MAXD = 50;
const int MAXN = MAXP + MAXD * 12 * 12 * 2;
const int MAXE = 2 * MAXP * MAXD * 12 * 12 * 2;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;

int ppl, R, C, lim, dist[15][15][15][15];
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
vector<pair<int, int>> doors;
char grid[15][15];

int head[MAXN], nxt[MAXE], to[MAXE], cap[MAXE], last;
bool vis[MAXN];

void BFS(int sr, int sc) {
	dist[sr][sc][sr][sc] = 0;
	queue<int> Q;
	Q.push(sr);
	Q.push(sc);
	while (Q.size()) {
		int r = Q.front();
		Q.pop();
		int c = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (nr < 0 || nr == R || nc < 0 || nc == C || grid[nr][nc] == 'X'
					|| grid[nr][nc] == 'D')
				continue;
			if (dist[sr][sc][nr][nc] == -1) {
				dist[sr][sc][nr][nc] = dist[sr][sc][r][c] + 1;
				Q.push(nr);
				Q.push(nc);
			}
		}
	}
}

void addEdge(int f, int t, int c) {
	to[last] = t;
	nxt[last] = head[f];
	cap[last] = c;
	head[f] = last++;
}

void addAugEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, 0);
}

bool DFS(int idx) {
	if (idx == SNK)
		return true;
	vis[idx] = 1;
	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (!vis[to[i]] && cap[i] && DFS(to[i])) {
			cap[i]--, cap[i ^ 1]++;
			return true;
		}
	}
	return false;
}

int check(int t) {
	memset(head, -1, sizeof head), last = 0;
	for (int i = 0; i < (int) doors.size(); i++)
		for (int tt = 1; tt <= t; tt++)
			addAugEdge(ppl + i * lim + tt - 1, SNK, 1);
	int cnt = -1;
	for (int rr = 0; rr < R; rr++) {
		for (int cc = 0; cc < C; cc++) {
			if (grid[rr][cc] != '.')
				continue;
			cnt++;
			addAugEdge(SRC, cnt, 1);
			for (int j = 0; j < (int) doors.size(); j++) {
				int r = doors[j].first, c = doors[j].second;
				if (dist[r][c][rr][cc] == -1)
					continue;
				for (int tt = dist[r][c][rr][cc]; tt <= t; tt++)
					addAugEdge(cnt, ppl + j * lim + tt - 1, 1);
			}
		}
	}
	int ret = 0;
	while (memset(vis, 0, sizeof vis), DFS(SRC))
		ret++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		ppl = 0, doors.clear();
		memset(dist, -1, sizeof dist);
		scanf("%d%d", &R, &C);
		lim = R * C * 2;
		for (int i = 0; i < R; i++) {
			scanf("%s", grid[i]);
			for (int j = 0; j < C; j++) {
				if (grid[i][j] == '.')
					ppl++;
				else if (grid[i][j] == 'D')
					doors.push_back( { i, j });
			}
		}
		for (int i = 0; i < (int) doors.size(); i++)
			BFS(doors[i].first, doors[i].second);
		int s = 1, e = lim;
		while (s < e) {
			int mid = (s + e) / 2;
			if (check(mid) < ppl)
				s = mid + 1;
			else
				e = mid;
		}
		if (s == lim)
			printf("impossible\n");
		else
			printf("%d\n", s);
	}
	return 0;
}
