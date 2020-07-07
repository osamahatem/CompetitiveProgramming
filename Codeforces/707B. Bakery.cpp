/*
 * 707B. Bakery.cpp
 *
 *  Created on: Aug 24, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int u[100005], v[100005], l[100005];
bool kk[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &u[i], &v[i], &l[i]);
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		kk[x] = 1;
	}
	int ans = 1 << 30;
	for (int i = 0; i < m; i++)
		if (kk[u[i]] ^ kk[v[i]])
			ans = min(ans, l[i]);
	printf("%d\n", ans == (1 << 30) ? -1 : ans);
	return 0;
}
