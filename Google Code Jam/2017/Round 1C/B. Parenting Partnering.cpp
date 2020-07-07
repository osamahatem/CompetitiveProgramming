/*
 * B. Parenting Partnering.cpp
 *
 *  Created on: Apr 30, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int DAY = 24 * 60;

bool ac[DAY], aj[DAY];
int dp[DAY][DAY / 2][2][2];

int solve(int idx, int mc, int mj, int last, int first) {
	if (idx == DAY)
		return last == first ? 0 : 1;
	int &ret = dp[idx][mc][last][first];
	if (~ret)
		return ret;
	ret = DAY;
	if (!ac[idx] && mc)
		ret = min(ret,
				solve(idx + 1, mc - 1, mj, 0, idx ? first : 0)
						+ (idx && last ? 1 : 0));
	if (!aj[idx] && mj)
		ret = min(ret,
				solve(idx + 1, mc, mj - 1, 1, idx ? first : 1)
						+ (idx && !last ? 1 : 0));
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
		memset(ac, 0, sizeof ac);
		memset(aj, 0, sizeof aj);
		memset(dp, -1, sizeof dp);
		int nc, nj, s, e;
		scanf("%d%d", &nc, &nj);
		while (nc--) {
			scanf("%d%d", &s, &e);
			while (s < e)
				ac[s++] = 1;
		}
		while (nj--) {
			scanf("%d%d", &s, &e);
			while (s < e)
				aj[s++] = 1;
		}
		printf("Case #%d: %d\n", t, solve(0, DAY / 2, DAY / 2, 0, 0));
	}
	return 0;
}
