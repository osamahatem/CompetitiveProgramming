/*
 * 429A. Xor-tree.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int init[MAXN], goal[MAXN];
int head[MAXN], to[2 * MAXN], nxt[2 * MAXN], last = 0;
vector<int> ans;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t) {
	addEdge(f, t);
	addEdge(t, f);
}

int solve(int n, int dep, int par, int even, int odd) {
	int cur = 0, ret = 0;
	if (dep % 2) {
		cur = (init[n] + odd) % 2;
		if (cur != goal[n])
			ret++, odd = (odd + 1) % 2;
	} else {
		cur = (init[n] + even) % 2;
		if (cur != goal[n])
			ret++, even = (even + 1) % 2;
	}
	if (cur != goal[n])
		ans.push_back(n);
	for (int i = head[n]; i != -1; i = nxt[i])
		if (to[i] != par)
			ret += solve(to[i], dep + 1, n, even, odd);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	int n, u, v;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		addBiEdge(u, v);
	}
	for (int i = 1; i <= n; i++)
		cin >> init[i];
	for (int i = 1; i <= n; i++)
		cin >> goal[i];
	printf("%d\n", solve(1, 0, 0, 0, 0));
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d\n", ans[i]);
	return 0;
}
