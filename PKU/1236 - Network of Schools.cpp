/*
 * 1236 - Network of Schools.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: Osama Hatem
 */

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

const int MAXN = 105;
const int MAXE = MAXN * MAXN;

int n;
int head[MAXN], nxt[MAXE], to[MAXE], last;
int vis[MAXN], indx[MAXN], low[MAXN], id;
int compID[MAXN], degIN[MAXN], degOUT[MAXN], comp;
stack<int> S;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void SCC(int idx) {
	vis[idx] = 1, S.push(idx);
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
			compID[cur] = comp;
		} while (cur != idx);
		comp++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int t;
		while (scanf("%d", &t), t)
			addEdge(i, t);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			SCC(i);
	int ans1 = comp, ans2, cntIN = 0, cntOUT = 0;
	for (int i = 1; i <= n; i++) {
		for (int e = head[i]; e != -1; e = nxt[e]) {
			if (compID[i] != compID[to[e]]) {
				if (!degIN[compID[to[e]]])
					ans1--;
				degIN[compID[to[e]]]++, degOUT[compID[i]]++;
			}
		}
	}
	for (int i = 0; i < comp; i++)
		cntIN += !degIN[i], cntOUT += !degOUT[i];
	ans2 = comp > 1 ? max(cntIN, cntOUT) : 0;
	printf("%d\n%d\n", ans1, ans2);
	return 0;
}
