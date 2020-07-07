/*
 * The Pipeline.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int r, c;
	long long cost;

	const bool operator <(const node &a) const {
		return cost > a.cost;
	}
};

const int MAXN = 1005;

int grid[MAXN][MAXN], n;
bool vis[MAXN][MAXN];

long long Dijkstra() {
	priority_queue<node> Q;
	node cur;
	for (int i = 1; i <= n; i++)
		Q.push(node { i, 1, 0 });
	while (Q.size()) {
		cur = Q.top();
		Q.pop();
		if (cur.c > n)
			return cur.cost;
		if (cur.r < 1 || cur.r > n || vis[cur.r][cur.c])
			continue;
		vis[cur.r][cur.c] = 1;
		Q.push(node { cur.r, cur.c + 1, cur.cost + grid[cur.r][cur.c] });
		Q.push(node { cur.r - 1, cur.c, cur.cost + grid[cur.r][cur.c] });
		Q.push(node { cur.r + 1, cur.c, cur.cost + grid[cur.r][cur.c] });
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &grid[i][j]);
	printf("%lld\n", Dijkstra());
	return 0;
}
