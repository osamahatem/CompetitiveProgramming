/*
 * B. Slides.cpp
 *
 *  Created on: May 8, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int b;
long long m;
bool edges[55][55];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(edges, 0, sizeof edges);
		printf("Case #%d: ", t);
		scanf("%d%lld", &b, &m);
		bool ans = (1ll << (b - 2)) >= m;
		printf("%s\n", (ans ? "POSSIBLE" : "IMPOSSIBLE"));
		for (int i = 1; i + 1 < b; i++) {
			int pi = (b - i - 2);
			if ((1ll << pi) < m)
				edges[0][i] = edges[i][b - 1] = 1;
			for (int j = i + 1; j + 1 < b; j++) {
				int pj = (b - j - 2);
				if ((1ll << pi) + (1ll << pj) < m)
					edges[0][i] = edges[i][j] = edges[j][b - 1] = 1;
			}
		}
		edges[0][b - 1] = 1;
		edges[0][0] = edges[b - 1][b - 1] = 0;
		if (ans)
			for (int i = 0; i < b; i++)
				for (int j = 0; j < b; j++) {
					printf("%d", edges[i][j]);
					if (j == b - 1)
						printf("\n");
				}
	}
	return 0;
}
