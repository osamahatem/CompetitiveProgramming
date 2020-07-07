/*
 * 604C. Alternative Thinking.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, n1[MAXN], n0[MAXN], dp[MAXN][3][3];
char in[MAXN];

int solve(int idx, int last, int swap) {
	if (idx == n)
		return 0;
	int &ret = dp[idx][last][swap];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1, last, swap);
	if (in[idx] - '0' != last && swap != 1)
		ret = max(ret, 1 + solve(idx + 1, in[idx] - '0', swap));
	if (in[idx] - '0' == last && !swap)
		ret = max(ret, 1 + solve(idx + 1, 1 - (in[idx] - '0'), 1));
	if (1 - (in[idx] - '0') != last && swap == 1)
		ret = max(ret, 1 + solve(idx + 1, 1 - (in[idx] - '0'), swap));
	if (in[idx] - '0' != last && swap == 1)
		ret = max(ret, 1 + solve(idx + 1, in[idx] - '0', 2));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	scanf("%d%s", &n, in);
	int c1 = n, c0 = n;
	for (int i = n - 1; i >= 0; i--) {
		n1[i] = c1, n0[i] = c0;
		if (in[i] == '0')
			c0 = i;
		else
			c1 = i;
	}
	printf("%d\n", solve(0, 2, 0));
	return 0;
}
