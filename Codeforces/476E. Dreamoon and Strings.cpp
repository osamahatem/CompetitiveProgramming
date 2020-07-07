/*
 * 476E. Dreamoon and Strings.cpp
 *
 *  Created on: Jun 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char s[2005], p[505];
int match[2005], dp[2005][2005], plen;

int solve(int idx, int left) {
	if (left < -1)
		return -(1 << 20);
	if (!s[idx])
		return (!left ? 0 : -(1 << 20));
	int &ret = dp[idx][left];
	if (ret != -1)
		return ret;
	ret = max(solve(idx + 1, left), solve(idx + 1, left - 1));
	if (match[idx] != -1) {
		int diff = (match[idx] - idx + 1) - plen;
		ret = max(ret, 1 + solve(match[idx] + 1, left - diff));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	scanf("%s%s", s, p);
	plen = strlen(p);
	for (int i = 0; s[i]; i++) {
		int len = 0, j;
		for (j = i; s[j] && p[len]; j++, len++)
			if (s[j] != p[len])
				len--;
		match[i] = !p[len] ? j - 1 : -1;
	}
	for (int i = 0; s[i]; i++)
		printf("%d ", solve(0, i));
	printf("0\n");
	return 0;
}
