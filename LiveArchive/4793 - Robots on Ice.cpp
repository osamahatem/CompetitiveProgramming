/*
 * 4793 - Robots on Ice.cpp
 *
 *  Created on: Feb 12, 2018
 *      Author: Osama Hatem
 */
 
/*
Use backtracking to do a complete search to generate all valid tours. This on
its own will not pass in time though, so we need to use some optimisations to
stop searching the current path and backtrack early. This code does so when one
of the following is true:
-	It reaches a checkpoint cell out of its intended order.
-	The Manhattan distance between the current cell and the next checkpoint is
	larger than the difference between its intended time step and the current
	time step.
-	The only valid movements are either up and down, or right and left: this
	means the current path split the grid into two separate parts and it can
	only reach one.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

#define valid(r, c) ((r) >= 0 && (r) < n && (c) >= 0 && (c) < m && !vis[(r)][(c)])

using namespace std;

int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };
int n, m, ans;
int st[5], sr[5], sc[5];
bool vis[8][8];

int solve(int r, int c, int s, int tar) {
	for (int i = 1; i < 5; i++)
		if (r == sr[i] && sc[i] == c && s != st[i])
			return 0;
	if (r == sr[4] && c == sc[4])
		return 1;

	if (r == sr[tar] && c == sc[tar])
		tar++;
	if (abs(r - sr[tar]) + abs(c - sc[tar]) > st[tar] - s)
		return 0;

	int cnt = 0, val[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < 4; i++)
		if (valid(r + dr[i], c + dc[i]))
			cnt++, val[i] = 1;
	if (cnt == 2 && ((val[0] && val[2]) || (val[1] && val[3])))
		return 0;

	int ret = 0;
	vis[r][c] = 1;
	for (int i = 0; i < 4; i++)
		if (val[i])
			ret += solve(r + dr[i], c + dc[i], s + 1, tar);
	vis[r][c] = 0;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T = 0;
	st[0] = 1, sr[0] = sc[0] = 0;
	while (cin >> n >> m, n) {
		cin >> sr[1] >> sc[1];
		cin >> sr[2] >> sc[2];
		cin >> sr[3] >> sc[3];
		for (int i = 1; i < 4; i++)
			st[i] = i * n * m / 4;
		st[4] = n * m, sr[4] = 0, sc[4] = 1;
		cout << "Case " << ++T << ": " << solve(0, 0, 1, 1) << endl;
	}
	return 0;
}
