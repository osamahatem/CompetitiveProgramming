/*
 * 305E. Playing with String.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[5001];
int len, piles = 0, dp[5000];
vector<int> pile, pileEqu, pileStart;

int solve(int p) {
	if (!p)
		return 0;
	int &ret = dp[p];
	if (ret != -1)
		return ret;
	int vis = -1;
	for (int i = 1; i <= p; i++) {
		int x = solve(max(0, i - 2)) ^ solve(max(0, p - i - 1));
		vis &= ~(1 << x);
	}
	ret = 0, vis = vis & -vis;
	while (vis >> 1)
		vis >>= 1, ret++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", in);
	len = strlen(in);
	bool active = false;
	for (int i = 1; i + 1 < len; i++) {
		if (in[i - 1] == in[i + 1]) {
			if (!active)
				piles++, pile.push_back(1), pileStart.push_back(i);
			else
				pile[piles - 1]++;
			active = true;
		} else
			active = false;
	}
	memset(dp, -1, sizeof dp);
	int res = 0;
	for (int i = 0; i < piles; i++) {
		pileEqu.push_back(solve(pile[i]));
		res ^= pileEqu[i];
	}
	printf("%s\n", res ? "First" : "Second");
	if (res)
		for (int i = 0; i < piles; i++) {
			int p = pileEqu[i];
			for (int j = 1; j <= pile[i]; j++) {
				int pp = solve(max(0, j - 2)) ^ solve(max(0, pile[i] - j - 1));
				if ((res ^ p ^ pp) == 0) {
					printf("%d\n", pileStart[i] + j);
					return 0;
				}
			}
		}
	return 0;
}
