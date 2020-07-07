/*
 * 332E. Binary Key.cpp
 *
 *  Created on: Jul 30, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char p[1000005], s[205];
int k, kk, plen, slen, cycles, ext, dp[2005][205];
bool can[2005][205];

int solveDP(int idx, int left, int used) {
	if (idx == k)
		return dp[idx][left] = left == 0;
	if (idx == plen % k && used * (cycles + 1) + left * cycles != slen)
		return dp[idx][left] = 0;
	int &ret = dp[idx][left];
	if (ret != -1)
		return ret;
	ret = solveDP(idx + 1, left, used);
	if (left && can[idx][used])
		ret |= solveDP(idx + 1, left - 1, used + 1);
	return ret;
}

string solve(int ones) {
	int len = ones * cycles;
	ext = slen - len;
	if (ext > plen % k)
		return string(2005, '1');
	for (int i = 0; i < slen; i++)
		for (int j = 0; j < k; j++) {
			can[j][i] = 1;
			for (int ii = i, jj = j; ii < slen && jj < plen; ii += ones, jj +=
					kk)
				if (p[jj] != s[ii])
					can[j][i] = 0;
		}
	memset(dp, -1, sizeof dp);
	if (!solveDP(0, ones, 0))
		return string(2005, '1');
	int idx = 0, left = ones;
	string ret = "";
	while (idx < k) {
		if (dp[idx + 1][left])
			ret += "0", idx++;
		else
			ret += "1", idx++, left--;
	}
	while (idx < kk)
		ret += "0", idx++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	gets(p);
	gets(s);
	scanf("%d", &kk);
	plen = strlen(p), slen = strlen(s);
	k = min(plen, kk);
	cycles = plen / k;
	int ones = slen / cycles;
	string ans(2005, '1');
	while (min(ones, plen % k) * (cycles + 1)
			+ (ones - min(ones, plen % k)) * cycles >= slen) {
		ans = min(ans, solve(ones));
		ones--;
	}
	if (ans == string(2005, '1'))
		printf("0\n");
	else
		printf("%s\n", ans.c_str());
	return 0;
}
