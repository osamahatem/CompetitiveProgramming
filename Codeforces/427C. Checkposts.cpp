/*
 * 427C. Checkposts.cpp
 *
 *  Created on: Jun 29, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXE = 3e5 + 5;
const int MOD = 1000000007;

int head[MAXN], nxt[MAXE], to[MAXE], last = 0;
int lowlink[MAXN], index[MAXN], _index = 0;
bool inS[MAXN];
stack<int> S;
vector<vector<int>> components;
int N, M, cost[MAXN];

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void SCC(int node) {
	lowlink[node] = index[node] = _index++;
	S.push(node), inS[node] = 1;
	for (int i = head[node]; i != -1; i = nxt[i])
		if (index[to[i]] == -1) {
			SCC(to[i]);
			lowlink[node] = min(lowlink[node], lowlink[to[i]]);
		} else if (inS[to[i]])
			lowlink[node] = min(lowlink[node], index[to[i]]);
	if (lowlink[node] == index[node]) {
		int cur;
		vector<int> scc;
		do {
			cur = S.top();
			S.pop();
			inS[cur] = 0;
			scc.push_back(cur);
		} while (cur != node);
		components.push_back(scc);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	memset(index, -1, sizeof index);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> cost[i];
	cin >> M;
	int u, v;
	while (M--) {
		cin >> u >> v;
		addEdge(u, v);
	}
	for (int i = 1; i <= N; i++)
		if (index[i] == -1)
			SCC(i);
	long long totalCost = 0, totalWays = 1;
	for (int i = 0; i < (int) components.size(); i++) {
		int mini = 1 << 30, cnt = 1;
		for (int j = 0; j < (int) components[i].size(); j++)
			if (cost[components[i][j]] < mini)
				mini = cost[components[i][j]], cnt = 1;
			else if (cost[components[i][j]] == mini)
				cnt++;
		totalCost += mini;
		totalWays = totalWays * cnt % MOD;
	}
	cout << totalCost << " " << totalWays << endl;
	return 0;
}
