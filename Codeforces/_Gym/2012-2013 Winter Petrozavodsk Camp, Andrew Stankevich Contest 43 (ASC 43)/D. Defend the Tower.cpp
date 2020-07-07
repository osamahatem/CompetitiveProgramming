/*
 * D. Defend the Tower.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const string tiles = ".GRS";
const int SZ = 10;
const int cost[4] = { 0, 3, 10, 5 };

int h;
pair<int, string> ans[101];
int hp[SZ], cell[SZ], delay[SZ], step[SZ], gun[SZ];

string maskToString(int mask) {
	string ret = "";
	for (int i = 0; i < SZ; i++) {
		ret += tiles[mask & 3];
		mask >>= 2;
	}
	return ret;
}

void fix(int idx, int sz) {
	for (int i = idx; i + 1 < sz; i++) {
		swap(hp[i], hp[i + 1]);
		swap(cell[i], cell[i + 1]);
		swap(delay[i], delay[i + 1]);
		swap(step[i], step[i + 1]);
	}
}

void solve(int mask) {
	string field = maskToString(mask);
	int cnt = SZ, kill = 0, t = 1;
	for (int i = 0; i < SZ; i++)
		hp[i] = h, cell[i] = -i - 1, delay[i] = 1, step[i] = gun[i] = 0;

	while (cnt) {
		for (int i = 0; i < cnt; i++) {
			if (t == step[i] + delay[i]) {
				cell[i]++, step[i] = t;
				if (cell[i] == SZ) {
					fix(i, cnt);
					cnt--, i--;
					continue;
				} else {
					if (cell[i] >= 0 && field[cell[i]] == 'S')
						delay[i]++;
					if (cell[i] >= 5 && field[cell[i] - 5] == 'S')
						delay[i]--;
				}
			}

			if (field[cell[i]] == 'G' && gun[cell[i]] != t) {
				hp[i]--, gun[cell[i]] = t;
				if (hp[i] < 1) {
					fix(i, cnt);
					cnt--, i--, kill++;
					continue;
				}
			} else if (field[cell[i]] == 'R' && t % 3 == 0) {
				hp[i] -= 4;
				if (hp[i] < 1) {
					fix(i, cnt);
					cnt--, i--, kill++;
					continue;
				}
			}
		}

		t++;
	}
	pair<int, string> temp = make_pair(-kill, field);
	int tot = 0;
	for (char c : field)
		tot += cost[tiles.find(c)];
	if (temp < ans[tot])
		ans[tot] = temp;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("defend.in", "r", stdin);
	freopen("defend.out", "w", stdout);

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> h;
	for (int i = 0; i < (1 << (SZ << 1)); i++)
		solve(i);
	for (int i = 1; i <= 100; i++) {
		ans[i] = min(ans[i], ans[i - 1]);
		if (ans[i].first != ans[i - 1].first)
			cout << "$" << i << " -> kill " << -ans[i].first << " with "
					<< ans[i].second << endl;
	}
	return 0;
}
