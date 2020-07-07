/*
 * C. Chairs.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct edge {
	int d, p, c;

	const bool operator <(const edge &e) const {
		if (d != e.d)
			return d < e.d;
		if (p != e.p)
			return p < e.p;
		return c < e.c;
	}
};

bool per[1005], ch[1005];
int x[1005], y[1005];

int dist(int x1, int y1, int x2, int y2) {
	int dx = x1 - x2, dy = y1 - y2;
	return dx * dx + dy * dy;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("chairs.in", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		memset(per, 0, sizeof per);
		memset(ch, 0, sizeof ch);
		vector<edge> all;
		int n, a, b;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		for (int i = 0; i <= n; i++) {
			cin >> a >> b;
			for (int j = 0; j < n; j++)
				all.push_back(edge { dist(a, b, x[j], y[j]), i, j });
		}
		sort(all.begin(), all.end());
		for (int i = 0; i < (int) all.size(); i++)
			if (!per[all[i].p] && !ch[all[i].c])
				per[all[i].p] = 1, ch[all[i].c] = 1;
		for (int i = 0; i <= n; i++)
			if (!per[i])
				cout << i + 1 << endl;
	}
	return 0;
}
