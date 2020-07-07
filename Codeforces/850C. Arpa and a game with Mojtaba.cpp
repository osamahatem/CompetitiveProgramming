/*
 * 850C. Arpa and a game with Mojtaba.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
map<int, int> dp, masks;

int solve(int mask) {
	if (mask < 2)
		return 0;
	if (dp.count(mask))
		return dp[mask];
	set<int> res;
	for (int i = 1; mask >> i; i++)
		res.insert(solve((mask & ((1 << i) - 1)) | (mask >> i)));
	int ret = 0;
	while (res.count(ret))
		ret++;
	return dp[mask] = ret;
}

void factorize(int x) {
	for (int i = 2; i <= x / i; i++) {
		int p = 0;
		while (x % i == 0)
			x /= i, p++;
		if (p)
			masks[i] |= 1 << p;
	}
	if (x > 1)
		masks[x] |= 1 << 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		factorize(x);
	}
	int res = 0;
	for (auto it : masks)
		res ^= solve(it.second);
	printf("%s\n", res ? "Mojtaba" : "Arpa");
	return 0;
}
