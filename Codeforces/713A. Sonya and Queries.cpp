/*
 * 713A. Sonya and Queries.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char ty[2], param[20];
string sty, sparam;
int trie[1800005][2], cnt[1800005], nodes;

void insert() {
	int cur = 0;
	cnt[0]++;
	for (int i = 0; sparam[i]; i++) {
		int nxt = (sparam[i] - '0') & 1;
		if (trie[cur][nxt] == -1)
			trie[cur][nxt] = ++nodes;
		cur = trie[cur][nxt];
		cnt[cur]++;
	}
}

void remove() {
	int cur = 0;
	cnt[0]--;
	for (int i = 0; sparam[i]; i++) {
		int nxt = (sparam[i] - '0') & 1;
		cur = trie[cur][nxt];
		cnt[cur]--;
	}
}

int solve() {
	int cur = 0;
	for (int i = 0; sparam[i]; i++) {
		int nxt = (sparam[i] - '0') & 1;
		if (trie[cur][nxt] == -1)
			return 0;
		cur = trie[cur][nxt];
	}
	return cnt[cur];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(trie, -1, sizeof trie);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", ty, param);
		sty = ty, sparam = param;
		while (sparam.size() < 18)
			sparam = "0" + sparam;
		if (sty == "+")
			insert();
		else if (sty == "-")
			remove();
		else
			printf("%d\n", solve());
	}
	return 0;
}
