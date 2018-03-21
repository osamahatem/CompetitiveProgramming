/*
 * 591E. Three States.cpp
 *
 *  Created on: Mar 21, 2018
 *      Author: Osama Hatem
 */
 
/*
The answer is the minimum of the following two cases:
	1-	Get the distances between pairs, and use the shortest two, like an MST.
	2-	The paths overlap, or rather meet in a cell. For this, pre-calculate all
		distances to all points from the three blocks, try all possible
		meeting points, and take the minimum.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int dr[] = { 1, -1, 0, 0 };
const int dc[] = { 0, 0, 1, -1 };
const int INF = 1e7;

int n, m, dist[4][1005][1005];
char grid[1005][1005];

bool valid(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#';
}

void bfs(char src, int dist[1005][1005]) {
	queue<int> Q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == src)
				Q.push(i * m + j), dist[i][j] = 0;
			else
				dist[i][j] = INF;
	while (Q.size()) {
		int r = Q.front() / m, c = Q.front() % m;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (valid(nr, nc) && dist[r][c] + 1 < dist[nr][nc])
				Q.push(nr * m + nc), dist[nr][nc] = dist[r][c] + 1;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> grid[i];

	bfs('1', dist[1]);
	bfs('2', dist[2]);
	bfs('3', dist[3]);

	int temp[3] = { INF, INF, INF };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == '2')
				temp[0] = min(temp[0], dist[1][i][j]);
			else if (grid[i][j] == '3')
				temp[1] = min(temp[1], dist[1][i][j]), temp[2] = min(temp[2],
						dist[2][i][j]);
	sort(temp, temp + 3);
	int ans = temp[0] + temp[1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == '.')
				ans = min(ans, dist[1][i][j] + dist[2][i][j] + dist[3][i][j]);

	if (ans >= INF)
		ans = -1;
	else
		ans -= 2;
	cout << ans << endl;
	return 0;
}
