/*
 * 706D. Vasiliy's Multiset.cpp
 *
 *  Created on: Aug 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int trie[6000000][2], cnt[6000000][2], cur;

void insert(int x) {
	int n = 0;
	for (int i = 29; i >= 0; i--) {
		int nxt = (x >> i) & 1;
		if (trie[n][nxt] == -1)
			trie[n][nxt] = ++cur;
		cnt[n][nxt]++;
		n = trie[n][nxt];
	}
}

void remove(int x) {
	int n = 0;
	for (int i = 29; i >= 0; i--) {
		int nxt = (x >> i) & 1;
		cnt[n][nxt]--;
		n = trie[n][nxt];
	}
}

int solve(int x) {
	int n = 0, ans = 0;
	for (int i = 29; i >= 0; i--) {
		int nxt = !((x >> i) & 1);
		if (trie[n][nxt] == -1 || cnt[n][nxt] == 0)
			nxt = !nxt;
		ans |= nxt << i;
		n = trie[n][nxt];
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(trie, -1, sizeof trie);
	insert(0);
	int q, x;
	char in[2];
	scanf("%d", &q);
	while (q--) {
		scanf("%s%d", in, &x);
		if (in[0] == '+')
			insert(x);
		else if (in[0] == '-')
			remove(x);
		else
			printf("%d\n", solve(x) ^ x);
	}
	return 0;
}
