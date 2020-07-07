/*
 * 6528 - Disjoint water supply.cpp
 *
 *  Created on: Jul 31, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e3 + 5;
const int MAXE = 1e5 + 5;

int head[MAXN], next[MAXE], to[MAXE], memo[MAXN][MAXN], last;

void init() {
	last = 0;
	memset(memo, -1, sizeof memo);
	memset(head, -1, sizeof head);
}

void addEdge(int f, int t) {
	next[last] = head[f];
	to[last] = t;
	head[f] = last++;
}

int disjoint(int a, int b) {
	if (a == b)
		return (bool) (a == 1);
	int &ret = memo[a][b];
	if (ret != -1)
		return ret;
	ret = 0;
	if (a > b) {
		for (int i = head[a]; i != -1; i = next[i])
			if (disjoint(to[i], b))
				return ret = 1;
		return ret;
	}
	for (int i = head[b]; i != -1; i = next[i])
		if (disjoint(a, to[i]))
			return ret = 1;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int c, p;
	while (scanf("%d%d", &c, &p) != EOF) {
		init();
		int u, v;
		while (p--) {
			scanf("%d%d", &u, &v);
			addEdge(v, u);
		}
		int ans = 0;
		for (int i = 1; i <= c; i++)
			for (int j = i + 1; j <= c; j++)
				ans += disjoint(i, j);
		printf("%d\n", ans);
	}
	return 0;
}
