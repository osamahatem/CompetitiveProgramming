/*
 * 514C. Watto and Mechanism.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int trie[600005][3], nodes = 0;
bool EOW[600005];

void insert(string &S) {
	int cur = 0;
	for (int i = 0; i < (int) S.size(); i++) {
		if (trie[cur][S[i] - 'a'] != -1)
			cur = trie[cur][S[i] - 'a'];
		else
			cur = trie[cur][S[i] - 'a'] = ++nodes;
	}
	EOW[cur] = 1;
}

bool query(int idx, string &S, int cur, bool mis) {
	if (idx == (int) S.size() && EOW[cur])
		return mis;
	for (int i = 0; i < 3; i++) {
		if (trie[cur][i] == -1)
			continue;
		if (S[idx] - 'a' == i && query(idx + 1, S, trie[cur][i], mis))
			return true;
		if (S[idx] - 'a' != i && !mis && query(idx + 1, S, trie[cur][i], 1))
			return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(trie, -1, sizeof trie);
	int n, m;
	cin >> n >> m;
	string S;
	while (n--) {
		cin >> S;
		insert(S);
	}
	while (m--) {
		cin >> S;
		cout << (query(0, S, 0, 0) ? "YES" : "NO") << endl;
	}
	return 0;
}
