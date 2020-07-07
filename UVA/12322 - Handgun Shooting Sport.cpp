/*
 * 12322 - Handgun Shooting Sport.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e3 + 5;
const double EPS = 1e-9;

struct event {
	double ang;
	int t, id;

	const bool operator <(const event &a) const {
		if (fabs(ang - a.ang) < EPS)
			return t == 1;
		return ang < a.ang;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	event all[2 * MAXN];
	int n;
	bool vis[MAXN];
	while (cin >> n, n) {
		memset(vis, 0, sizeof vis);
		int x1, y1, x2, y2;
		for (int i = 0; i < n; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			double a = atan2(y1, x1);
			double b = atan2(y2, x2);
			all[2 * i] = event { min(a, b), 1, i };
			all[2 * i + 1] = event { max(a, b), -1, i };
		}
		sort(all, all + 2 * n);
		queue<int> Q;
		int ans = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (vis[all[i].id])
				continue;
			if (all[i].t == 1)
				Q.push(all[i].id);
			if (all[i].t == -1) {
				ans++;
				while (Q.size()) {
					vis[Q.front()] = 1;
					Q.pop();
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
