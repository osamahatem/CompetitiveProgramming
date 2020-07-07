/*
 * J. Computer Network.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;
const int MAXE = 2e5 + 5;

int n, m;
int head[MAXN], nxt[MAXE], to[MAXE], last = 2;
int indx[MAXN], low[MAXN], idx;
int sum[MAXN];
bool vis[MAXN], bridge[MAXE];
int maxi = -1, au = -1, av = -1;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void tarjan(int node, int p) {
	vis[node] = 1, indx[node] = low[node] = ++idx;
	for (int i = head[node]; ~i; i = nxt[i]) {
		if (!vis[to[i]]) {
			tarjan(to[i], i);
			low[node] = min(low[node], low[to[i]]);
			if (low[to[i]] > indx[node]) {
				bridge[i] = 1, bridge[i ^ 1] = 1;
			}
		} else if (i != (p ^ 1)) {
			low[node] = min(low[node], indx[to[i]]);
		}
	}
}

vector<int> solve(int node) {
	vis[node] = 1;
	vector<int> ret;
	bool leaf = 1;
	for (int i = head[node]; ~i; i = nxt[i])
		if (!vis[to[i]]) {
			leaf = 0;
			sum[to[i]] = sum[node] + bridge[i];
			vector<int> temp = solve(to[i]);
			if (temp.size() > ret.size())
				swap(temp, ret);
			for (int i = 0; i < (int) ret.size(); i++) {
				for (int j = 0; j < (int) temp.size(); j++) {
					int cur = sum[ret[i]] + sum[temp[j]] - 2 * sum[node];
					if (cur > maxi)
						maxi = cur, au = ret[i], av = temp[j];
				}
			}
			for (int i = 0; i < (int) temp.size(); i++)
				ret.push_back(temp[i]);
		}
	if (leaf) {
		if (sum[node] > maxi)
			maxi = sum[node], au = 1, av = node;
		ret.push_back(node);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	memset(head, -1, sizeof head);
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v), addEdge(v, u);
	}
	tarjan(1, 0);
	memset(vis, 0, sizeof vis);
	solve(1);
	printf("%d %d\n", au, av);
	return 0;
}
