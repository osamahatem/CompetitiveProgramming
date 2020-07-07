/*
 * 492E. Vanya and Field.cpp
 *
 *  Created on: Aug 9, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int posx[MAXN], posy[MAXN], diff[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, dx, dy, maxi = 0, xx = -1, yy = -1;
	scanf("%d%d%d%d", &n, &m, &dx, &dy);
	posx[0] = posy[0] = 0;
	int x = dx, y = dy;
	for (int i = 1; x; i++, x = (x + dx) % n, y = (y + dy) % n)
		posx[x] = posy[y] = i;
	while (m--) {
		scanf("%d%d", &x, &y);
		int d = posx[x] - posy[y];
		if (d < 0)
			d += n;
		if (++diff[d] > maxi)
			maxi = diff[d], xx = x, yy = y;
	}
	printf("%d %d\n", xx, yy);
	return 0;
}
