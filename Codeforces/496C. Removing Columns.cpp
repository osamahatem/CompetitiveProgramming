/*
 * 496C. Removing Columns.cpp
 *
 *  Created on: Dec 17, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char grid[1005][1005];
int n, m;
vector<pair<int, int> > check[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	check[0].push_back(make_pair(0, n - 1));
	int c = 0, ans = 0;
	while (c < m && check[c].size()) {
		for (int i = 0; i < (int) check[c].size(); i++) {
			int s = check[c][i].first;
			int e = check[c][i].second;
			for (int j = s; j < e; j++) {
				if (grid[j][c] > grid[j + 1][c]) {
					ans++;
					check[c + 1] = check[c];
					goto ss;
				}
			}
		}
		for (int i = 0; i < (int) check[c].size(); i++) {
			int s = check[c][i].first;
			int e = check[c][i].second;
			for (int j = s; j < e; j++) {
				if (grid[j][c] == grid[j + 1][c]) {
					int ss = j, ee = j;
					while (ee < n && ee <= e && grid[ee][c] == grid[ss][c])
						ee++;
					ee--;
					j = ee;
					check[c + 1].push_back(make_pair(ss, ee));
				}
			}
		}
		ss: c++;
	}
	cout << ans << endl;
	return 0;
}
