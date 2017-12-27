/*
 * 909C. Python Indentation.cpp
 *
 *  Created on: Dec 27, 2017
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56666
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5005;

int n, dp[2][MAXN];
char in[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%*c%c", &in[i]);
	for (int i = 0; i <= n; i++)
		dp[n & 1][i] = 1;
	for (int i = n - 1; ~i; i--) {
		int ii = i & 1;
		int ni = ii ^ 1;
		for (int d = 0; d < n; d++) {
			if (in[i] == 'f') {
				dp[ii][d] = dp[ni][d + 1];
			} else {
				dp[ii][d] = dp[ni][d];
				if (d && i + 1 < n)
					dp[ii][d] = (dp[ii][d] + dp[ii][d - 1]) % MOD;
			}
		}
	}
	printf("%d\n", dp[0][0]);
	return 0;
}
