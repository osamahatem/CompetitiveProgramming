/*
 * 320B. Ping-Pong (Easy Version).cpp
 *
 *  Created on: May 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool reach[105][105];
vector<pair<int, int> > ints;
int sz;

bool check(int a, int b) {
	if (ints[a].first > ints[b].first && ints[a].first < ints[b].second)
		return true;
	if (ints[a].second > ints[b].first && ints[a].second < ints[b].second)
		return true;
	return false;
}

void update_reach() {
	for (int k = 0; k < sz; k++)
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				reach[i][j] = (reach[i][j] || (reach[i][k] && reach[k][j]));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, t, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> x >> y;
		if (t == 1) {
			ints.push_back(make_pair(x, y));
			reach[sz][sz] = 1;
			for (int i = 0; i < sz; i++) {
				if (check(i, sz))
					reach[i][sz] = 1;
				if (check(sz, i))
					reach[sz][i] = 1;
			}
			sz++;
			update_reach();
		} else {
			x--, y--;
			cout << (reach[x][y] ? "YES" : "NO") << endl;
		}
	}
	return 0;
}
