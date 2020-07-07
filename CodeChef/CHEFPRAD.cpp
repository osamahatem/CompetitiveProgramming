/*
 * CHEFPRAD.cpp
 *
 *  Created on: Jun 3, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, M;
long long e, c[255], d[255];

int maxMatch(long long diff) {
	int ret = 0;
	for (int i = 0, j = 0; i < N; i++) {
		while (j < M && d[j] + e < c[i] + diff)
			j++;
		if (j == M)
			break;
		if (c[i] + diff < d[j] - e)
			continue;
		ret++, j++;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%lld", &N, &M, &e);
		for (int i = 0; i < N; i++)
			scanf("%lld", &c[i]);
		for (int i = 0; i < M; i++)
			scanf("%lld", &d[i]);
		sort(c, c + N);
		sort(d, d + M);
		int ans = maxMatch(0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				ans = max(ans, maxMatch(d[j] - e - 1 - c[i]));
				ans = max(ans, maxMatch(d[j] - e - c[i]));
				ans = max(ans, maxMatch(d[j] + e + 1 - c[i]));
				ans = max(ans, maxMatch(d[j] + e - c[i]));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
