/*
 * SUBXOR.cpp
 *
 *  Created on: May 25, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int BITS = 21;

int n, k, arr[MAXN];
int trie[BITS * MAXN][2], cnt[BITS * MAXN], nodes = 0;

void insert(int x) {
	int cur = 0;
	cnt[cur]++;
	for (int i = BITS; ~i; i--) {
		int bit = (x >> i) & 1;
		if (trie[cur][bit] == -1)
			trie[cur][bit] = ++nodes;
		cur = trie[cur][bit];
		cnt[cur]++;
	}
}

int solve(int x, int idx, int bitIdx, bool smaller) {
	if (smaller || bitIdx < 0)
		return cnt[idx];
	int bit_k = (k >> bitIdx) & 1;
	int bit_x = (x >> bitIdx) & 1;
	int ret = 0;
	if ((bit_x ^ 1) <= bit_k && trie[idx][1] != -1)
		ret += solve(x, trie[idx][1], bitIdx - 1, (bit_x ^ 1) < bit_k ? 1 : 0);
	if ((bit_x ^ 0) <= bit_k && trie[idx][0] != -1)
		ret += solve(x, trie[idx][0], bitIdx - 1, (bit_x ^ 0) < bit_k ? 1 : 0);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(trie, -1, sizeof trie);
		memset(cnt, 0, sizeof cnt);
		nodes = 0;
		scanf("%d%d", &n, &k);
		k--;
		insert(0);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			arr[i] ^= arr[i - 1];
			insert(arr[i]);
		}
		long long ans = 0;
		for (int i = 0; i <= n; i++)
			ans += solve(arr[i], 0, BITS, 0);
		ans = (ans - n - 1) / 2;
		printf("%lld\n", ans);
	}
	return 0;
}
