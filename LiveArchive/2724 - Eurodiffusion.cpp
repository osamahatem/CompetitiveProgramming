/*
 * 2724 - Eurodiffusion.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: Osama Hatem
 */
 
/*
The upper-bound on the answer is small enough that the problem can be solved
simply by simulating.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };
const int sz = 10;

struct node {
	string name;
	int ans;

	bool operator <(const node &rhs) const {
		if (ans != rhs.ans)
			return ans < rhs.ans;
		return name < rhs.name;
	}
};

int n, country[15][15], cnt[15][15][25], temp[15][15][25], rem[25];
bool comp[15][15];
node all[25];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t = 0;
	while (cin >> n, n) {
		memset(country, -1, sizeof country);
		memset(cnt, 0, sizeof cnt);
		memset(comp, 0, sizeof comp);

		int x1, y1, x2, y2;
		for (int i = 0; i < n; i++) {
			cin >> all[i].name >> x1 >> y1 >> x2 >> y2;
			rem[i] = (x2 - x1 + 1) * (y2 - y1 + 1);
			for (int r = x1; r <= x2; r++)
				for (int c = y1; c <= y2; c++)
					country[r][c] = i, cnt[r][c][i] = 1000000;
		}

		int done = 0;
		for (int st = 0; done < n; st++) {
			for (int i = 1; i <= sz; i++) {
				for (int j = 1; j <= sz; j++) {
					if (country[i][j] == -1)
						continue;
					bool flag = true;
					for (int k = 0; k < n; k++)
						flag &= cnt[i][j][k] > 0;
					if (flag && !comp[i][j]) {
						comp[i][j] = 1;
						if (rem[country[i][j]] == 1)
							all[country[i][j]].ans = st, done++;
						rem[country[i][j]]--;
					}
				}
			}

			memcpy(temp, cnt, sizeof temp);
			for (int i = 1; i <= sz; i++) {
				for (int j = 1; j <= sz; j++) {
					for (int k = 0; k < n; k++) {
						int c = temp[i][j][k] / 1000;
						for (int d = 0; d < 4; d++) {
							int ii = i + dr[d], jj = j + dc[d];
							if (country[ii][jj] == -1)
								continue;
							cnt[ii][jj][k] += c, cnt[i][j][k] -= c;
						}
					}
				}
			}
		}

		sort(all, all + n);
		cout << "Case Number " << ++t << endl;
		for (int i = 0; i < n; i++)
			cout << "   " << all[i].name << "   " << all[i].ans << endl;
	}
	return 0;
}
