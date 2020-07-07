/*
 * 555C. Case of Chocolate - Intervals.cpp
 *
 *  Created on: Jun 28, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct piece {
	int s, e, u, l;

	const bool operator <(const piece &p) const {
		return e < p.e;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, q, x, y;
	char t;
	set<piece> pieces;
	set<piece>::iterator it;
	piece cur, n1, n2;
	scanf("%d%d", &n, &q);
	pieces.insert(piece { 1, n, 1, 1 });
	while (q--) {
		scanf("%d%d%*c%c", &x, &y, &t);
		it = pieces.lower_bound(piece { 0, x, 0, 0 });
		if (it == pieces.end() || it->s > x) {
			printf("0\n");
			continue;
		}
		cur = *it;
		pieces.erase(it);
		n1 = n2 = cur;
		n1.e = x - 1;
		n2.s = x + 1;
		if (t == 'U') {
			n2.l = x + 1;
			printf("%d\n", y - cur.u + 1);
		} else {
			n1.u = y + 1;
			printf("%d\n", x - cur.l + 1);
		}
		if (n1.e >= n1.s)
			pieces.insert(n1);
		if (n2.e >= n2.s)
			pieces.insert(n2);
	}
	return 0;
}
