/*
 * A. Alphabet.cpp
 *
 *  Created on: Oct 10, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dp[55];
char str[55];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", str);
	int len = strlen(str);
	dp[len] = 0;
	for (int i = len - 1; ~i; i--)
		for (int j = i + 1; j <= len; j++)
			if (str[j] > str[i] || j == len)
				dp[i] = max(dp[i], 1 + dp[j]);
	int ans = 0;
	for (int i = 0; i < len; i++)
		ans = max(ans, dp[i]);
	printf("%d\n", 26 - ans);
	return 0;
}
