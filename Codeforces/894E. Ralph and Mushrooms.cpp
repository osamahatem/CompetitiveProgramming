/*
 * 894E. Ralph and Mushrooms.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int n, m;
vector<pair<int, int>> adj[MAXN];

int low[MAXN], idx[MAXN], id;
bool inS[MAXN];
int scc_id[MAXN], scc;
stack<int> S;

vector<pair<int, int>> scc_adj[MAXN];
vector<int> scc_edges[MAXN];
long long val[MAXN], dp[MAXN];

void tarjan(int node) {
	low[node] = idx[node] = ++id;
	S.push(node), inS[node] = 1;
	for (pair<int, int> e : adj[node]) {
		if (idx[e.first] == 0) {
			tarjan(e.first);
			low[node] = min(low[node], low[e.first]);
		} else if (inS[e.first])
			low[node] = min(low[node], idx[e.first]);
	}
	if (low[node] == idx[node]) {
		int cur;
		do {
			cur = S.top();
			S.pop(), inS[cur] = 0;
			scc_id[cur] = scc;
		} while (cur != node);
		scc++;
	}
}

long long solve(int node) {
	long long &ret = dp[node];
	if (~ret)
		return ret;
	ret = 0;
	for (pair<int, int> e : scc_adj[node])
		ret = max(ret, solve(e.first) + e.second);
	ret += val[node];
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	while (m--) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		adj[x].push_back(make_pair(y, w));
	}
	for (int i = 1; i <= n; i++)
		if (idx[i] == 0)
			tarjan(i);
	for (int i = 1; i <= n; i++)
		for (pair<int, int> e : adj[i]) {
			int x = scc_id[i], y = scc_id[e.first];
			if (x == y)
				scc_edges[x].push_back(e.second);
			else
				scc_adj[x].push_back(make_pair(y, e.second));
		}
	for (int i = 0; i < scc; i++) {
		sort(scc_edges[i].begin(), scc_edges[i].end());
		long long sum = 0;
		int idx = 0, cum = 0;
		for (int w : scc_edges[i])
			sum += w;
		for (int j = 0; idx < (int) scc_edges[i].size(); j++) {
			cum += j;
			while (idx < (int) scc_edges[i].size() && scc_edges[i][idx] < cum) {
				sum -= scc_edges[i][idx];
				idx++;
			}
			val[i] += sum - 1ll * cum * ((int) scc_edges[i].size() - idx);
		}
	}
	int s;
	scanf("%d", &s);
	memset(dp, -1, sizeof dp);
	printf("%lld\n", solve(scc_id[s]));
	return 0;
}
