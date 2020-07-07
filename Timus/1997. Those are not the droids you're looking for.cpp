/*
 * 1997. Those are not the droids you're looking for.cpp
 *
 *  Created on: Aug 4, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1005;
const int MAXE = MAXN * MAXN;
const int src = MAXN - 1;
const int snk = MAXN - 2;

int head[MAXN], to[MAXE], cap[MAXE], nxt[MAXE], last = 0;
int par[MAXN], vis[MAXN], id = 1;

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

bool getPath(int cur) {
	if (cur == snk)
		return true;
	if (vis[cur] == id)
		return false;
	vis[cur] = id;
	for (int i = head[cur]; i != -1; i = nxt[i]) {
		if (cap[i] && getPath(to[i])) {
			cap[i]--;
			cap[i ^ 1]++;
			par[to[i]] = cur;
			return true;
		}
	}
	return false;
}

int maxFlow() {
	int ans = 0;
	while (getPath(src))
		id++, ans++;
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int a, b, n, t, s;
	int times[MAXN];
	bool out[MAXN];
	memset(head, -1, sizeof head);
	scanf("%d%d%d", &a, &b, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &t, &s);
		times[i] = t;
		if (!s) {
			addAugEdge(src, i, 1);
			out[i] = 0;
		} else {
			out[i] = 1;
			addAugEdge(i, snk, 1);
			for (int j = 0; j < i; j++)
				if (!out[j] && (t - times[j] <= b || t - times[j] >= a))
					addAugEdge(j, i, 1);
		}
	}
	if (maxFlow() == n / 2) {
		printf("No reason\n");
		for (int i = 0; i < n; i++)
			if (out[i])
				printf("%d %d\n", times[par[i]], times[i]);
	} else
		printf("Liar\n");
	return 0;
}
