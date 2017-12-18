/*
 * SHORTCUT.cpp
 *
 *  Created on: Dec 18, 2017
 *      Author: Osama Hatem
 */
 
/*
Try shortcuts in all 4 directions from all points in the path, if valid. Break
ties as described in the problem statement. Nice implementation problem.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const string DIR = "NESW";
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };

struct node {
	int l, s, e;
	char d;

	bool operator <(const node &rhs) const {
		if (l != rhs.l)
			return l < rhs.l;
		if (s != rhs.s)
			return s < rhs.s;
		return e > rhs.e;
	}
};

map<int, set<pair<int, int>>> r, c;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		r.clear(), c.clear();

		int n;
		string in;
		cin >> n >> in;

		int x = 0, y = 0;
		r[x].insert(make_pair(y, 0));
		c[y].insert(make_pair(x, 0));

		node ans = { (int) 1e6, (int) 1e6, (int) 1e6, 'W' };

		for (int i = 0; i < (int) in.size(); i++) {
			int d = DIR.find(in[i]);
			x += dr[d], y += dc[d];
			r[x].insert(make_pair(y, i + 1));
			c[y].insert(make_pair(x, i + 1));

			auto it = r[x].lower_bound(make_pair(y, 0));

			if (it != r[x].begin() && in[i] != 'E') {
				it--;
				node temp = { y - it->first, it->second, i + 1, 'E' };
				if (temp < ans)
					ans = temp;
				it++;
			}

			it++;
			if (it != r[x].end() && in[i] != 'W') {
				node temp = { it->first - y, it->second, i + 1, 'W' };
				if (temp < ans)
					ans = temp;
			}

			it = c[y].lower_bound(make_pair(x, 0));

			if (it != c[y].begin() && in[i] != 'S') {
				it--;
				node temp = { x - it->first, it->second, i + 1, 'S' };
				if (temp < ans)
					ans = temp;
				it++;
			}

			it++;
			if (it != c[y].end() && in[i] != 'N') {
				node temp = { it->first - x, it->second, i + 1, 'N' };
				if (temp < ans)
					ans = temp;
			}
		}
		cout << ans.l << " " << ans.s << " " << ans.e << " " << ans.d << endl;
	}
	return 0;
}
