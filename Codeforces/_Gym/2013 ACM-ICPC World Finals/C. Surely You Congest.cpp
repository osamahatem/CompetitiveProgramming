/*
 * 6395 - Surely You Congest.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 25e3 + 5;
const int MAXE = 103e3;
const int SRC = MAXN - 1;
const int SNK = 1;
const int INF = 1e9;

int n, m, c;
int head[MAXN], nxt[MAXE], to[MAXE], cap[MAXE], cost[MAXE], last;
int head_bak[MAXN], cap_bak[MAXE], last_bak;
int dist[MAXN], par[MAXN];

void add_edge(int f, int t, int _cap, int _cost) {
	to[last] = t;
	cap[last] = _cap;
	cost[last] = _cost;
	nxt[last] = head[f];
	head[f] = last++;
}

void add_bi_edge(int f, int t, int _cap, int _cost) {
	add_edge(f, t, _cap, _cost);
	add_edge(t, f, 0, _cost);
}

void dijkstra() {
	memset(dist, 127, sizeof dist);
	set<pair<int, int>> S;
	S.insert(make_pair(0, SNK)), dist[SNK] = 0;
	while (S.size()) {
		int cur = S.begin()->second;
		S.erase(S.begin());
		for (int i = head[cur]; ~i; i = nxt[i]) {
			int dist_new = dist[cur] + cost[i], t = to[i];
			if (dist_new < dist[t]) {
				S.erase(make_pair(dist[t], t));
				dist[t] = dist_new;
				S.insert(make_pair(dist[t], t));
			}
		}
	}
}

bool bfs() {
	memset(par, -1, sizeof par);
	queue<int> Q;
	Q.push(SRC), par[SRC] = INF;
	while (Q.size()) {
		int cur = Q.front();
		Q.pop();
		for (int i = head[cur]; ~i; i = nxt[i])
			if (par[to[i]] == -1 && cap[i])
				Q.push(to[i]), par[to[i]] = i;
	}
	return par[SNK] != -1;
}

int dfs(int cur = SRC, int flow = INF) {
	if (cur == SNK)
		return flow;
	int f;
	for (int i = head[cur]; ~i; i = nxt[i])
		if (par[to[i]] == i && (f = dfs(to[i], min(flow, cap[i])))) {
			cap[i] -= f, cap[i ^ 1] += f;
			return f;
		}
	return 0;
}

int dinic() {
	int flow = 0;
	while (bfs())
		flow += dfs();
	return flow;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> n >> m >> c) {
		memset(head, -1, sizeof head), last = 0;

		for (int i = 0; i < m; i++) {
			int x, y, t;
			cin >> x >> y >> t;
			add_bi_edge(x, y, 1, t);
		}

		dijkstra();

		map<int, vector<int>> groups;
		for (int i = 0; i < c; i++) {
			int x;
			cin >> x;
			groups[dist[x]].push_back(x);
		}

		vector<pair<int, int>> temp;
		for (int i = 1; i <= n; i++)
			for (int j = head[i]; ~j; j = nxt[j])
				if (dist[i] - cost[j] == dist[to[j]])
					temp.push_back(make_pair(i, to[j]));

		memset(head, -1, sizeof head), last = 0;
		for (auto p : temp)
			add_bi_edge(p.first, p.second, 1, 0);

		last_bak = last;
		memcpy(head_bak, head, sizeof head);
		memcpy(cap_bak, cap, sizeof cap);

		int ans = 0;
		for (auto g : groups) {
			for (auto v : g.second)
				add_bi_edge(SRC, v, 1, 0);
			ans += dinic();
			last = last_bak;
			memcpy(head, head_bak, sizeof head);
			memcpy(cap, cap_bak, sizeof cap);
		}
		cout << ans << endl;
	}
	return 0;
}
