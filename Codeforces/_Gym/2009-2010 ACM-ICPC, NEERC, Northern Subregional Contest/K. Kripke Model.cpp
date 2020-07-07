/*
 * K. Kripke Model.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;

int n, m, k, a, b;
bool st[MAXN][26];
vector<int> adj[MAXN];
vector<pair<int, int>> edges;

stack<int> S;
bool inS[MAXN];
int low[MAXN], index[MAXN], scc_id[MAXN], id;
vector<vector<int>> SCCs;

int memA[MAXN], memB[MAXN];
bool target[MAXN];

void tarjan(int idx) {
	low[idx] = index[idx] = ++id;
	S.push(idx), inS[idx] = true;
	for (auto ch : adj[idx]) {
		if (index[ch] == 0) {
			tarjan(ch);
			low[idx] = min(low[idx], low[ch]);
		} else if (inS[ch]) {
			low[idx] = min(low[idx], index[ch]);
		}
	}
	if (low[idx] == index[idx]) {
		int cur;
		vector<int> scc;
		do {
			cur = S.top();
			S.pop(), inS[cur] = false;
			scc_id[cur] = SCCs.size();
			scc.push_back(cur);
		} while (cur != idx);
		SCCs.push_back(scc);
	}
}

int solveB(int idx) {
	int &ret = memB[idx];
	if (~ret)
		return ret;
	ret = 1;
	for (int i = 0; i < (int) SCCs[idx].size(); i++)
		ret &= st[SCCs[idx][i]][b];
	for (auto ch : adj[idx])
		ret &= solveB(ch);
	return ret;
}

int solveA(int idx) {
	int &ret = memA[idx];
	if (~ret)
		return ret;
	ret = 0;
	for (int i = 0; i < (int) SCCs[idx].size(); i++)
		ret |= target[SCCs[idx][i]];
	for (auto ch : adj[idx])
		ret |= solveA(ch);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("kripke.in", "r", stdin);
	freopen("kripke.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		int x;
		char c[3];
		scanf("%d", &x);
		while (x--) {
			scanf("%s", c);
			st[i][c[0] - 'a'] = 1;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		edges.push_back(make_pair(u, v));
	}
	for (int i = 1; i <= n; i++)
		if (index[i] == 0)
			tarjan(i);

	char in[15];
	scanf("%s", in);
	a = in[2] - 'a', b = in[7] - 'a';

	memset(memB, -1, sizeof memB);
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	for (int i = 0; i < m; i++)
		if (scc_id[edges[i].first] != scc_id[edges[i].second])
			adj[scc_id[edges[i].first]].push_back(scc_id[edges[i].second]);
	for (int i = 1; i <= n; i++)
		target[i] = solveB(scc_id[i]);

	for (int i = 1; i <= n; i++)
		adj[i].clear();
	SCCs.clear(), id = 0;
	memset(index, 0, sizeof index);
	memset(scc_id, -1, sizeof scc_id);
	for (int i = 0; i < m; i++)
		if (st[edges[i].first][a]
				&& (st[edges[i].second][a] || target[edges[i].second]))
			adj[edges[i].first].push_back(edges[i].second);
	for (int i = 1; i <= n; i++)
		if ((st[i][a] || target[i]) && index[i] == 0)
			tarjan(i);
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	for (int i = 0; i < m; i++)
		if (scc_id[edges[i].first] != scc_id[edges[i].second]
				&& scc_id[edges[i].first] != -1
				&& scc_id[edges[i].second] != -1)
			adj[scc_id[edges[i].first]].push_back(scc_id[edges[i].second]);
	memset(memA, -1, sizeof memA);
	vector<int> ans;
	for (int i = 1; i <= n; i++)
		if ((st[i][a] || target[i]) && (solveA(scc_id[i])))
			ans.push_back(i);
	printf("%d\n", ans.size());
	for (auto idx : ans)
		printf("%d\n", idx);
	return 0;
}
