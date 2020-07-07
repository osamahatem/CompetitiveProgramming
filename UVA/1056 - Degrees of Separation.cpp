/*
 * 1056 - Degrees of Separation.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<string, int> rnk;
int n, m, r, t, dist[50][50];
char a[25], b[25];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &n, &m), n || m) {
		rnk.clear(), r = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = (i == j ? 0 : n + 1);
		while (m--) {
			scanf("%s%s", a, b);
			if (!rnk.count(a))
				rnk[a] = r++;
			if (!rnk.count(b))
				rnk[b] = r++;
			dist[rnk[a]][rnk[b]] = dist[rnk[b]][rnk[a]] = 1;
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans = max(ans, dist[i][j]);
		printf("Network %d: ", ++t);
		if (ans == n + 1)
			printf("DISCONNECTED\n\n");
		else
			printf("%d\n\n", ans);
	}
	return 0;
}
