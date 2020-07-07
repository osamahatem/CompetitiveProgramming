/*
 * B. Roller Coaster Scheduling.cpp
 *
 *  Created on: May 13, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, C, M, tpc[1005], tps[1005];

int check(int rides) {
	int temp[1005], ret = 0;
	memcpy(temp, tps, sizeof temp);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			while (temp[j] < rides && temp[i] > rides)
				temp[j]++, temp[i]--, ret++;
		if (temp[i] > rides)
			return -1;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(tpc, 0, sizeof tpc);
		memset(tps, 0, sizeof tps);
		scanf("%d%d%d", &N, &C, &M);
		for (int i = 0; i < M; i++) {
			int p, b;
			scanf("%d%d", &p, &b);
			tpc[--b]++, tps[--p]++;
		}
		int s = *max_element(tpc, tpc + C), e = M;
		while (s < e) {
			int mid = (s + e) / 2;
			if (check(mid) == -1)
				s = mid + 1;
			else
				e = mid;
		}
		printf("Case #%d: %d %d\n", t, s, check(s));
	}
	return 0;
}
