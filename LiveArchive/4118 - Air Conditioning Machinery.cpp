/*
 * 4118 - Air Conditioning Machinery.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: Osama Hatem
 */
 
/*
Each elbow piece can be placed such that its first part is in the same direction
as the second part of the previous piece (or the direction of the inflow if this
is the first piece), and the second part in one of the four directions
perpendicular to it, so we have a total of 8 different orientations for any
piece (4 directions * 2 (longer part first vs. shorter part first)).
Since we are limited to 6 pieces, we have a total of 8^6 combinations, which is
roughly 256,000. This is small enough that we can write a backtracking code to
try everything and pick the smallest answer.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dx[] = { 1, 0, 0, -1, 0, 0 };
int dy[] = { 0, 1, 0, 0, -1, 0 };
int dz[] = { 0, 0, 1, 0, 0, -1 };
string dir[] = { "+x", "+y", "+z", "-x", "-y", "-z" };

int X, Y, Z, sx, sy, sz, ex, ey, ez, ed;
string strs, stre;
bool vis[22][22][22];

bool valid(int x, int y, int z) {
	return x >= 1 && x <= X && y >= 1 && y <= Y && z >= 1 && z <= Z
			&& !vis[x][y][z];
}

int solve(int x, int y, int z, int d, int dpth) {
	if (x == ex && y == ey && z == ez && d == ed)
		return dpth;
	if (!valid(x, y, z) || dpth > 6)
		return 10;

	vis[x][y][z] = 1;
	int ret = 10;
	for (int i = 0; i < 6; ++i) {
		if (i == d || (i + 3) % 6 == d)
			continue;
		for (int j = 1; j <= 2; ++j) {
			int tx = x, ty = y, tz = z;
			vector<int> un;
			bool flag = true;
			for (int k = 0; k < j; ++k) {
				tx += dx[d], ty += dy[d], tz += dz[d];
				if (!valid(tx, ty, tz)) {
					flag = false;
					break;
				}
				un.push_back(tx);
				un.push_back(ty);
				un.push_back(tz);
				vis[tx][ty][tz] = 1;
			}
			for (int k = 0; flag && k < 3 - j; ++k) {
				tx += dx[i], ty += dy[i], tz += dz[i];
				if (!valid(tx, ty, tz)) {
					flag = false;
					break;
				}
				un.push_back(tx);
				un.push_back(ty);
				un.push_back(tz);
				vis[tx][ty][tz] = 1;
			}

			if (flag == true) {
				tx += dx[i], ty += dy[i], tz += dz[i];
				ret = min(ret, solve(tx, ty, tz, i, dpth + 1));
			}

			for (int i = 0, len = un.size(); i < len; i += 3)
				vis[un[i]][un[i + 1]][un[i + 2]] = 0;
		}
	}
	vis[x][y][z] = 0;
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
	while (cin >> X, X) {
		cin >> Y >> Z;
		cin >> sx >> sy >> sz >> strs;
		cin >> ex >> ey >> ez >> stre;

		ed = find(dir, dir + 6, stre) - dir;
		ex += dx[ed], ey += dy[ed], ez += dz[ed];
		int ans = solve(sx, sy, sz, find(dir, dir + 6, strs) - dir, 0);
		cout << "Case " << ++T << ": ";
		if (ans > 6)
			cout << "Impossible";
		else
			cout << ans;
		cout << endl;
	}
	return 0;
}
