/*
 * 12644 - Vocabulary.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e3 + 5;
const int MAXE = MAXN * MAXN;
const int src = MAXN - 1;
const int snk = MAXN - 2;

int head[MAXN], to[MAXE], cap[MAXE], nxt[MAXE], last;
int vis[MAXN], id = 1;

void init() {
	memset(head, -1, sizeof head);
	last = 0;
}

void addEdge(int f, int t, int c) {
	nxt[last] = head[f];
	to[last] = t;
	cap[last] = c;
	head[f] = last++;
}

void addAugEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, 0);
}

bool check(string v, string c) {
	int cnt[26];
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < (int) v.size(); i++)
		cnt[v[i] - 'a']++;
	for (int i = 0; i < (int) c.size(); i++)
		cnt[c[i] - 'a']--;
	for (int i = 0; i < 26; i++)
		if (cnt[i] < 0)
			return false;
	return true;
}

bool getPath(int cur) {
	if (cur == snk)
		return true;
	vis[cur] = id;
	for (int i = head[cur]; i != -1; i = nxt[i]) {
		int t = to[i];
		if (cap[i] && vis[t] != id && getPath(t)) {
			cap[i]--;
			cap[i ^ 1]++;
			return true;
		}
	}
	return false;
}

int maxFlow() {
	int ans = 0;
	while (++id, getPath(src))
		ans++;
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int V, C;
	string voc[MAXN / 2], temp;
	while (cin >> V >> C) {
		init();
		for (int i = 0; i < V; i++) {
			cin >> voc[i];
			addAugEdge(src, i, 1);
		}
		for (int i = 0; i < C; i++) {
			cin >> temp;
			addAugEdge(i + V, snk, 1);
			for (int j = 0; j < V; j++)
				if (check(voc[j], temp))
					addAugEdge(j, i + V, 1);
		}
		cout << maxFlow() << "\n";
	}
	return 0;
}
