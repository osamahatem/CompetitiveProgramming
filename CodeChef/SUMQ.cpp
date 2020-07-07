/*
 * SUMQ.cpp
 *
 *  Created on: Jun 2, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int a[MAXN], b[MAXN], c[MAXN], p, q, r;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &p, &q, &r);
		for (int i = 0; i < p; i++)
			scanf("%d", a + i);
		for (int i = 0; i < q; i++)
			scanf("%d", b + i);
		for (int i = 0; i < r; i++)
			scanf("%d", c + i);
		sort(a, a + p);
		sort(b, b + q);
		sort(c, c + r);
		int ans = 0, pi = 0, ri = 0, ps = 0, rs = 0;
		for (int qi = 0; qi < q; qi++) {
			while (pi < p && a[pi] <= b[qi])
				ps = (ps + a[pi++]) % MOD;
			while (ri < r && c[ri] <= b[qi])
				rs = (rs + c[ri++]) % MOD;
			int lhs = (1ll * b[qi] * ri % MOD + rs) % MOD;
			int rhs = (1ll * b[qi] * pi % MOD + ps) % MOD;
			ans = (ans + 1ll * rhs * lhs % MOD) % MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}
