/*
 * PSTRING.cpp
 *
 *  Created on: Jun 14, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dp[2][1005], fail[1005], newMatch[1005][26];
char x[10005], y[1005];

void computeFail() {
	fail[0] = 0;
	int len = 0;
	for (int i = 1; y[i]; i++) {
		while (len && y[len] != y[i])
			len = fail[len - 1];
		if (y[len] == y[i])
			len++;
		fail[i] = len;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%s%s", x, y) != -1) {
		computeFail();
		for (int i = 0; y[i]; i++) {
			for (int c = 0; c < 26; c++) {
				int x = i;
				while (x && y[x] != 'a' + c)
					x = fail[x - 1];
				if (y[x] == 'a' + c)
					x++;
				newMatch[i][c] = x;
			}
		}
		int len_x = strlen(x), len_y = strlen(y);
		memset(dp[len_x & 1], 0, sizeof dp[len_x & 1]);
		dp[len_x & 1][len_y] = 1 << 28;
		for (int i = len_x - 1; ~i; i--) {
			int ii = i & 1, iii = (i & 1) ^ 1;
			dp[ii][len_y] = 1 << 28;
			for (int j = 0; j < len_y; j++)
				dp[ii][j] = min(1 + dp[iii][j],
						dp[iii][newMatch[j][x[i] - 'a']]);
		}
		printf("%d\n", dp[0][0]);
	}
	return 0;
}

//	http://ideone.com/7VOPyZ	Recursive - No Pre-Processing
//	http://ideone.com/TPa3xb	Recursive - With Pre-Processing
//	http://ideone.com/qyk8kj	Iterative - With Memory Reduction
