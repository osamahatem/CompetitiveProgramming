/*
 * 455B. A Lot of Games.cpp
 *
 *  Created on: Jul 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int trie[MAXN][26], nodes;
char str[MAXN];

void insertInTrie() {
	int cur = 0;
	for (int i = 0; str[i]; i++) {
		int l = str[i] - 'a';
		if (trie[cur][l] == -1)
			trie[cur][l] = ++nodes;
		cur = trie[cur][l];
	}
}

bool win(int n) {
	bool ret = false;
	for (int i = 0; i < 26; i++)
		if (trie[n][i] != -1)
			ret |= !win(trie[n][i]);
	return ret;
}

bool lose(int n) {
	bool ret = true;
	for (int i = 0; i < 26; i++)
		if (trie[n][i] != -1)
			ret = false;
	for (int i = 0; i < 26; i++)
		if (trie[n][i] != -1)
			ret |= !lose(trie[n][i]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(trie, -1, sizeof trie);
	int n, k;
	scanf("%d%d", &n, &k);
	while (n--) {
		scanf("%s", str);
		insertInTrie();
	}
	bool w = win(0), l = lose(0);
	printf("%s\n", (w && (l || (!l && k % 2)) ? "First" : "Second"));
	return 0;
}
