/*
 * 467D. Fedor and Essay.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct word {
	string s;
	int r = 0;

	word() {
	}

	word(string ss) {
		r = 0, s = ss;
		for (int i = 0; i < (int) s.size(); i++) {
			s[i] = tolower(s[i]);
			r += s[i] == 'r';
		}
	}

	const bool operator <(const word &w) const {
		if (r != w.r)
			return r < w.r;
		if (s.size() != w.s.size())
			return s.size() < w.s.size();
		return s < w.s;
	}
};

map<word, vector<word>> adj;
map<word, vector<word>>::iterator it;
map<word, word> mini;
set<word> vis;
vector<word> essay;
word curSrc;
char in[500005], inn[500005];

void dfs(word cur) {
	vis.insert(cur);
	mini[cur] = curSrc;
	for (int i = 0; i < (int) adj[cur].size(); i++)
		if (!vis.count(adj[cur][i]))
			dfs(adj[cur][i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int m, n;
	scanf("%d", &m);
	essay.resize(m);
	for (int i = 0; i < m; i++) {
		scanf("%s", in);
		essay[i] = word(in);
		adj[essay[i]];
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%s%s", in, inn);
		word x = word(in), y = word(inn);
		adj[y].push_back(x);
	}
	for (it = adj.begin(); it != adj.end(); it++)
		if (!vis.count(it->first)) {
			curSrc = it->first;
			dfs(curSrc);
		}
	int rr = 0;
	long long len = 0;
	for (int i = 0; i < (int) essay.size(); i++) {
		essay[i] = mini[essay[i]];
		len += essay[i].s.size();
		rr += essay[i].r;
	}
	printf("%d %I64d\n", rr, len);
	return 0;
}
