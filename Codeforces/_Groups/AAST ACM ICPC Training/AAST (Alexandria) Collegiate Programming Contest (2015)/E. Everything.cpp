/*
 * E. Everything.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct fileData {
	string str;
	int id, ans;

	static const bool cmpByStr(const fileData& a, const fileData& b) {
		return a.str < b.str;
	}

	static const bool cmpById(const fileData& a, const fileData& b) {
		return a.id < b.id;
	}
};

int trie[500005][26], s[500005], e[500005], nodes;
vector<fileData> all;
char buff[100005];

void insert(int id) {
	string str = all[id].str;
	int cur = 0;
	e[0] = id;
	for (int i = 0; str[i]; i++) {
		if (trie[cur][str[i] - 'a'] == -1) {
			trie[cur][str[i] - 'a'] = ++nodes;
			cur = nodes;
			s[cur] = e[cur] = id;
		} else {
			cur = trie[cur][str[i] - 'a'];
			e[cur] = id;
		}
	}
}

int solve(int id) {
	string str = all[id].str;
	int cur = 0, ret = 1 + min(id, 1 + e[0] - id);
	for (int i = 0; str[i]; i++) {
		cur = trie[cur][str[i] - 'a'];
		ret = min(ret, i + 2 + min(id - s[cur], 1 + e[cur] - id));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("everything.in", "r", stdin);
	int T, N;
	scanf("%d", &T);
	while (T--) {
		memset(trie, -1, sizeof trie), nodes = 0;
		s[0] = 0;
		scanf("%d", &N);
		all.resize(N);
		for (int i = 0; i < N; i++) {
			scanf("%s", buff);
			all[i].str = buff, all[i].id = i;
		}
		sort(all.begin(), all.end(), fileData::cmpByStr);
		for (int i = 0; i < N; i++)
			insert(i);
		for (int i = 0; i < N; i++)
			all[i].ans = solve(i);
		sort(all.begin(), all.end(), fileData::cmpById);
		for (int i = 0; i < N; i++) {
			if (i)
				printf(" ");
			printf("%d", all[i].ans);
		}
		printf("\n");
	}
	return 0;
}
