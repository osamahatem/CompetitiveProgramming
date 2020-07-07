/*
 * 463D. Gargari and Permutations.cpp
 *
 *  Created on: Jul 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k, pos[5][1000], dp[1000];

int solve(int last) {
	int &ret = dp[last];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int i = 0; i < n; i++) {
		bool valid = true;
		for (int j = 0; j < k; j++)
			if (pos[j][i] <= pos[j][last])
				valid = false;
		if (valid)
			ret = max(ret, 1 + solve(i));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	int x;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			pos[i][--x] = j;
		}
	x = 0;
	for (int i = 0; i < n; i++)
		x = max(x, solve(i));
	printf("%d\n", x);
	return 0;
}
