/*
 * CAPCITY.cpp
 *
 *  Created on: Sep 30, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXE = 2e5 + 5;

int n, m, head[MAXN], nxt[MAXE], to[MAXE], last;
int comp[MAXN], deg[MAXN], compID;
int vis[MAXN], indx[MAXN], low[MAXN], id;
stack<int> S;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void SCC(int idx) {
	S.push(idx), vis[idx] = 1;
	indx[idx] = low[idx] = ++id;
	for (int i = head[idx]; i != -1; i = nxt[i]) {
		if (!vis[to[i]]) {
			SCC(to[i]);
			low[idx] = min(low[idx], low[to[i]]);
		} else if (vis[to[i]] == 1) {
			low[idx] = min(low[idx], indx[to[i]]);
		}
	}
	if (indx[idx] == low[idx]) {
		int cur;
		do {
			cur = S.top();
			S.pop(), vis[cur] = 2;
			comp[cur] = compID;
		} while (cur != idx);
		compID++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		addEdge(b, a);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			SCC(i);
	int cnt = compID;
	for (int i = 1; i <= n; i++)
		for (int e = head[i]; e != -1; e = nxt[e])
			if (comp[i] != comp[to[e]]) {
				if (!deg[comp[to[e]]])
					cnt--;
				deg[comp[to[e]]]++;
			}
	vector<int> ans;
	if (cnt == 1) {
		for (int i = 1; i <= n; i++)
			if (!deg[comp[i]])
				ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	if (ans.size())
		printf("\n");
	return 0;
}
