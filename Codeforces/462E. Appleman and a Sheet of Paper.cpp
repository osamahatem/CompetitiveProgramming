/*
 * 462E. Appleman and a Sheet of Paper.cpp
 *
 *  Created on: Jun 17, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, q, tree[100005];

void update(int idx, int val) {
	while (idx <= n) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

int query(int idx) {
	int ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int query(int l, int r) {
	return query(r) - query(l - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		update(i, 1);
	int start = 1, endd = n;
	bool flip = 0;
	while (q--) {
		int t, l, r;
		scanf("%d%d", &t, &l);
		if (t == 1) {
			if (l * 2 > endd - start + 1)
				flip = !flip, l = endd - start + 1 - l;
			if (flip)
				endd -= l;
			else
				start += l;
			for (int i = 0; i < l; i++)
				if (flip)
					update(endd - i, query(endd + i + 1, endd + i + 1));
				else
					update(start + i, query(start - i - 1, start - i - 1));
		} else {
			scanf("%d", &r);
			printf("%d\n",
					flip ? query(endd - r + 1, endd - l) : query(start + l,
									start + r - 1));
		}
	}
	return 0;
}
