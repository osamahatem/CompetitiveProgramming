/*
 * UNIONSET.cpp
 *
 *  Created on: Jun 3, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2505;

int N, K, len[MAXN], arr[MAXN][MAXN];
int vis[MAXN], id = 0;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int ans = 0;
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d", &len[i]);
			for (int j = 0; j < len[i]; j++)
				scanf("%d", &arr[i][j]);
			for (int j = 0; j < i; j++) {
				id++;
				int cnt = 0;
				for (int k = 0; k < len[i]; k++)
					if (vis[arr[i][k]] != id)
						vis[arr[i][k]] = id, cnt++;
				for (int k = 0; k < len[j]; k++)
					if (vis[arr[j][k]] != id)
						vis[arr[j][k]] = id, cnt++;
				if (cnt == K)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
