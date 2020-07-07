/*
 * 398B. Painting The Wall.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e3 + 5;

double prob[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, r, c;
	set<int> rs, cs;
	cin >> n >> m;
	while (m--) {
		cin >> r >> c;
		rs.insert(r);
		cs.insert(c);
	}
	r = n - (int) rs.size(), c = n - (int) cs.size();
	for (int rr = 0; rr <= r; rr++) {
		for (int cc = (bool) !rr; cc <= c; cc++) {
			double p1 = (double) (n - rr) * (n - cc) / (n * n);
			double p2 = (double) rr * (n - cc) / (n * n);
			double p3 = (double) (n - rr) * cc / (n * n);
			double p4 = (double) rr * cc / (n * n);
			if (rr)
				prob[rr][cc] += p2 * prob[rr - 1][cc];
			if (cc)
				prob[rr][cc] += p3 * prob[rr][cc - 1];
			if (rr && cc)
				prob[rr][cc] += p4 * prob[rr - 1][cc - 1];
			prob[rr][cc] += 1.0;
			prob[rr][cc] /= (1.0 - p1);
		}
	}
	cout << fixed << setprecision(4) << prob[r][c] << endl;
	return 0;
}
