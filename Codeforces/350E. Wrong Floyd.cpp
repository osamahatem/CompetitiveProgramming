/*
 * 350E. Wrong Floyd.cpp
 *
 *  Created on: Jul 20, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool check[305], edge[305][305];
pair<int, int> ans[90005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, m, c = 0, r = -1, s = -1;
	scanf("%d%d%d", &n, &m, &k);
	if (k == n) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		check[x] = 1;
		s = x;
	}
	for (int i = 1; i <= n; i++)
		if (!check[i])
			r = i;
	ans[c++] = make_pair(r, s), edge[r][s] = edge[s][r] = 1;
	int last = r;
	for (int i = 1; i <= n; i++) {
		if (i == r || i == s)
			continue;
		ans[c++] = make_pair(last, i), edge[last][i] = edge[i][last] = 1;
		last = i;
	}
	for (int i = 1; c < m && i <= n; i++)
		for (int j = i + 1; c < m && j <= n; j++) {
			if ((i == s && check[j]) || (check[i] && j == s) || edge[i][j])
				continue;
			ans[c++] = make_pair(i, j), edge[i][j] = edge[j][i] = 1;
		}
	if (c < m) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < m; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
