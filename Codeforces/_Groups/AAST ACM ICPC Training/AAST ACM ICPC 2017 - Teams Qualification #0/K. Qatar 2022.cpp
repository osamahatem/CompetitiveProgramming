/*
 * K. Qatar 2022.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int row[MAXN], col[MAXN];

void update(int tree[], int idx, int val) {
	for (; idx < MAXN; idx += idx & -idx)
		tree[idx] += val;
}

int query(int tree[], int idx) {
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += tree[idx];
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("qatar.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, q;
		scanf("%d%d%d", &n, &m, &q);
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);
		while (q--) {
			int t, x1, y1, x2, y2;
			scanf("%d%d", &t, &x1);
			if (t == 5) {
				scanf("%d%d%d", &y1, &x2, &y2);
				if (x2 < x1)
					swap(x1, x2);
				if (y2 < y1)
					swap(y1, y2);
				int cnt = query(row, x2) - query(row, x1) + query(col, y2)
						- query(col, y1);
				printf("%d\n", cnt ? -1 : max(x2 - x1, y2 - y1));
			} else {
				update(t < 3 ? row : col, x1, t & 1 ? 1 : -1);
			}
		}
	}
	return 0;
}
