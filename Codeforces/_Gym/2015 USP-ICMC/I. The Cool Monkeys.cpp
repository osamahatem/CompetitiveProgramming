/*
 * I. The Cool Monkeys.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXM = 505;
const int MAXN = 2005;
const int MAXE = 11e5 + 5;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;

int head[MAXN], to[MAXE], nxt[MAXE], cap[MAXE], last;
int thead[MAXN], tlast;
int vis[MAXN], id;
int m, na, nb, ah[MAXM], bh[MAXM], T;

void addEdge(int f, int t, int c) {
	to[last] = t;
	cap[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
}

void addAugEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, 0);
}

void addBiEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, c);
}

bool dfs(int n) {
	vis[n] = id;
	for (int i = head[n]; i != -1; i = nxt[i])
		if (cap[i] && vis[to[i]] != id && (to[i] == SNK || dfs(to[i]))) {
			cap[i]--, cap[i ^ 1]++;
			return true;
		}
	return false;
}

int maxFlow() {
	int ans = 0;
	while (id++, dfs(SRC))
		ans++;
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	cin >> m >> na >> nb >> T;
	for (int i = 0; i < na; i++)
		cin >> ah[i];
	for (int i = 0; i < nb; i++)
		cin >> bh[i];
	sort(ah, ah + na), sort(bh, bh + nb);
	for (int i = 0; i < na; i++)
		addBiEdge(i * 2, i * 2 + 1, 1);
	for (int i = 0; i < nb; i++) {
		addBiEdge(na * 2 + i * 2, na * 2 + i * 2 + 1, 1);
		for (int j = 0; j < na; j++)
			if (abs(ah[j] - bh[i]) < T) {
				addAugEdge(j * 2 + 1, na * 2 + i * 2 + 1, 1);
				addAugEdge(na * 2 + i * 2, j * 2, 1);
			}
	}
	tlast = last;
	memcpy(thead, head, sizeof head);
	for (int i = 0; i < m; i++) {
		addAugEdge(SRC, (na - 1 - i) * 2, 1);
		addAugEdge(na * 2 + i * 2, SNK, 1);
	}
	int ans = maxFlow();
	if (ans == m) {
		cout << "S" << endl;
		return 0;
	}
	last = tlast;
	memcpy(head, thead, sizeof head);
	for (int i = 0; i < m; i++) {
		addAugEdge(SRC, na * 2 + (nb - 1 - i) * 2, 1);
		addAugEdge(i * 2, SNK, 1);
	}
	ans = maxFlow();
	if (ans == m) {
		cout << "S" << endl;
		return 0;
	}
	cout << "N" << endl;
	return 0;
}
