/*
 * 12657 - Boxes in a Line.cpp
 *
 *  Created on: Aug 31, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = MAXN - 1;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, t = 0, left[MAXN], right[MAXN];
	while (cin >> n >> m) {
		cout << "Case " << ++t << ": ";
		for (int i = 1; i <= n; i++)
			left[i] = i - 1, right[i] = i + 1;
		right[n] = INF;
		left[INF] = n;
		right[0] = 1;
		bool rev = 0;
		int op, x, y;
		while (m--) {
			cin >> op;
			if (op == 4)
				rev = !rev;
			else {
				cin >> x >> y;
				if (op == 3) {
					int lx = left[x], rx = right[x];
					int ly = left[y], ry = right[y];
					right[lx] = y;
					left[rx] = y;
					right[ly] = x;
					left[ry] = x;
					swap(left[x], left[y]);
					swap(right[x], right[y]);
					continue;
				} else {
					int l = left[x], r = right[x];
					right[l] = r;
					left[r] = l;
					if ((op == 1 && !rev) || (op == 2 && rev))
						if (left[y] == x)
							continue;
						else
							l = left[y], r = y;
					else if (right[y] == x)
						continue;
					else
						l = y, r = right[y];
					left[x] = l;
					right[x] = r;
					right[l] = x;
					left[r] = x;
				}
			}
		}
		long long sum = 0;
		int cur, cnt = 0;
		if (rev) {
			cur = left[INF];
			while (cur != 0) {
				++cnt;
				if (cnt % 2)
					sum += cur;
				cur = left[cur];
			}
		} else {
			cur = right[0];
			while (cur != INF) {
				++cnt;
				if (cnt % 2)
					sum += cur;
				cur = right[cur];
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
