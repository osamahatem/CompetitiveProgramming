/*
 * 10401 - Injured Queen Problem.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long dp[15][15];
char in[20];
int n, pos[20];

long long solve(int last, int col) {
	if (col == n)
		return 1;
	if (pos[col] != -1) {
		if (col && abs(pos[col] - last) < 2)
			return 0;
		else
			return solve(pos[col], col + 1);
	}
	long long& ret = dp[last][col];
	if (~ret)
		return ret;
	ret = 0;
	for (int i = 0; i < n; i++) {
		if (col && abs(i - last) < 2)
			continue;
		ret += solve(i, col + 1);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%s", in) != EOF) {
		n = strlen(in);
		for (int i = 0; i < n; i++) {
			if (in[i] == '?')
				pos[i] = -1;
			else if (in[i] >= '0' && in[i] <= '9')
				pos[i] = in[i] - '1';
			else
				pos[i] = in[i] - 'A' + 9;
		}
		memset(dp, -1, sizeof dp);
		printf("%lld\n", solve(0, 0));
	}
	return 0;
}
