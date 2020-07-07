/*
 * 12664 - Interesting Calculator.cpp
 *
 *  Created on: Aug 31, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int x, y, app[10], add[10], mul[10];
bool vis[MAXN];

struct node {
	int cost, p, num;

	const bool operator <(const node &a) const {
		if (cost != a.cost)
			return cost > a.cost;
		return p > a.p;
	}
};

node Dijkstra() {
	priority_queue<node> Q;
	Q.push(node { 0, 0, x });
	while (Q.size()) {
		node cur = Q.top();
		Q.pop();
		if (cur.num == y)
			return cur;
		if (vis[cur.num])
			continue;
		vis[cur.num] = 1;
		for (int i = 0; i < 10; i++) {
			int nNum = cur.num * 10 + i, nCost = cur.cost + app[i];
			if (nNum <= y && !vis[nNum])
				Q.push(node { nCost, cur.p + 1, nNum });
			nNum = cur.num + i, nCost = cur.cost + add[i];
			if (nNum <= y && !vis[nNum])
				Q.push(node { nCost, cur.p + 1, nNum });
			nNum = cur.num * i, nCost = cur.cost + mul[i];
			if (nNum <= y && !vis[nNum])
				Q.push(node { nCost, cur.p + 1, nNum });
		}
	}
	return node { -1, -1, -1 };
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t = 0;
	while (cin >> x >> y) {
		memset(vis, 0, sizeof vis);
		cout << "Case " << ++t << ": ";
		for (int i = 0; i < 10; i++)
			cin >> app[i];
		for (int i = 0; i < 10; i++)
			cin >> add[i];
		for (int i = 0; i < 10; i++)
			cin >> mul[i];
		node ans = Dijkstra();
		cout << ans.cost << " " << ans.p << "\n";
	}
	return 0;
}
