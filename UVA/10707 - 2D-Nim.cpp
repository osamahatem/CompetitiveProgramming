/*
 * 10707 - 2D-Nim.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char grid[105][105];
map<vector<pair<int, int>>, int> cnt;
vector<pair<int, int>> comp;
int R, C, n, dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };

void resetGrid() {
	memset(grid, '.', sizeof grid);
	for (int i = 0; i < R; i++)
		grid[i][C] = 0;
}

void flood(int r, int c) {
	grid[r][c] = '$';
	comp.push_back(make_pair(r, c));
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		if (rr >= 0 && rr < R && cc >= 0 && c < C && grid[rr][cc] == '#')
			flood(rr, cc);
	}
}

void normalize(vector<pair<int, int>>& v) {
	int x = v[0].first, y = v[0].second;
	for (int i = 1; i < (int) v.size(); i++)
		x = min(x, v[i].first), y = min(y, v[i].second);
	for (int i = 0; i < (int) v.size(); i++)
		v[i].first -= x, v[i].second -= y;
	sort(v.begin(), v.end());
}

void rotate(vector<pair<int, int>>& v) {
	for (int i = 1; i < (int) v.size(); i++) {
		int dx = v[i].first - v[0].first, dy = v[i].second - v[0].second;
		v[i].first = v[0].first + dy, v[i].second = v[0].second - dx;
	}
}

void flip(vector<pair<int, int>>& v) {
	for (int i = 1; i < (int) v.size(); i++) {
		int dy = v[i].second - v[0].second;
		v[i].second = v[0].second - dy;
	}
}

vector<pair<int, int>> getComp() {
	normalize(comp);
	vector<pair<int, int>> ret = comp;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 4; i++) {
			rotate(comp);
			normalize(comp);
			ret = min(ret, comp);
		}
		flip(comp);
		normalize(comp);
	}
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
		cnt.clear();
		scanf("%d%d%d", &C, &R, &n);
		resetGrid();
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &y, &x);
			grid[x][y] = '#';
		}
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (grid[i][j] == '#') {
					comp.clear();
					flood(i, j);
					cnt[getComp()]++;
				}
		resetGrid();
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &y, &x);
			grid[x][y] = '#';
		}
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (grid[i][j] == '#') {
					comp.clear();
					flood(i, j);
					cnt[getComp()]--;
				}
		bool ans = true;
		for (auto it = cnt.begin(); it != cnt.end(); it++)
			if (it->second)
				ans = false;
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}
