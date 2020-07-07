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

int h, w, dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 }, id = 1;
int vis[1005][1005];

bool outOfBounds(int r, int c) {
	if (r < 0 || c < 0 || r == h || c == w)
		return true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t;
	long long cost[26], temp;
	char c, grid[1005][1005];
	scanf("%d", &t);
	while (t--) {
		++id;
		priority_queue<node> Q;
		int k;
		scanf("%d%d%d ", &k, &w, &h);
		while (k--) {
			scanf("%c%lld ", &c, &temp);
			cost[c - 'A'] = temp;
		}
		for (int i = 0; i < h; i++)
			scanf("%s", grid[i]);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (grid[i][j] == 'E')
					Q.push(node { i, j, 0 });

		while (Q.size()) {
			long long curCost = Q.top().cost;
			int curR = Q.top().r;
			int curC = Q.top().c;
			Q.pop();
			if (curR == 1001 && curC == 1001) {
				printf("%lld\n", curCost);
				break;
			}
			if (vis[curR][curC] == id)
				continue;
			vis[curR][curC] = id;
			for (int i = 0; i < 4; i++) {
				int newR = curR + dr[i], newC = curC + dc[i];
				long long newCost = curCost + cost[grid[newR][newC] - 'A'];
				if (outOfBounds(newR, newC))
					Q.push(node { 1001, 1001, curCost });
				else {
					if (vis[newR][newC] != id)
						Q.push(node { newR, newC, newCost });
				}
			}
		}
	}
	return 0;
}
