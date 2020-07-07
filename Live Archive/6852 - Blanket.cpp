/*
 * 6852 - Blanket.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int mod[17][17], ans[100005], temp[1000005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(mod, 0, sizeof mod);
		memset(ans, 0, sizeof ans);
		memset(temp, 0, sizeof temp);
		int n, m, a, b;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			for (int i = 0; i < a; i++)
				mod[b][i]++;
		}
		for (int i = 1; i <= 16; i++)
			for (int j = 0; j < m; j++)
				temp[j] += mod[i][j % i];
		for (int i = 0; i < m; i++)
			ans[temp[i]]++;
		for (int i = 0; i <= n; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}
