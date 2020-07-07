/*
 * 507E. Breaking Good.cpp
 *
 *  Created on: Jan 26, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXE = 2 * MAXN;

int head[MAXN], to[MAXE], cost[MAXE], nxt[MAXE], wrk[MAXE], id[MAXE], last;
bool vis[MAXN], used[MAXN];
long long dist[MAXN];
int prv[MAXN], edg[MAXN], tar;

struct node {
	int id;
	long long c;

	const bool operator <(const node &a) const {
		return c > a.c;
	}
};

struct edge {
	int u, v;
	bool z;
};

void addEdge(int f, int t, int c, int i, bool w) {
	nxt[last] = head[f];
	to[last] = t;
	cost[last] = c;
	wrk[last] = w;
	id[last] = i;
	head[f] = last++;
}

void addBiEdge(int f, int t, int c, int i, bool w) {
	addEdge(f, t, c, i, w);
	addEdge(t, f, c, i, w);
}

void Dijkstra() {
	priority_queue<node> Q;
	Q.push(node { 1, 0 });
	dist[1] = 0;
	while (Q.size()) {
		node cur = Q.top();
		Q.pop();
		int n = cur.id;
		long long c = cur.c;
		if (n == tar)
			break;
		if (vis[n])
			continue;
		vis[n] = 1;
		for (int i = head[n]; i != -1; i = nxt[i]) {
			long long nc = c + cost[i];
			int t = to[i];
			if (nc < dist[t]) {
				dist[t] = nc;
				prv[t] = n;
				edg[t] = id[i];
				Q.push(node { t, nc });
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	memset(prv, -1, sizeof prv);
	memset(edg, -1, sizeof edg);
	fill(dist, dist + MAXN, 1ll << 60);
	int n, m, u, v, c;
	bool z;
	vector<edge> all, ans;
	cin >> n >> m;
	tar = n, c = n + 1;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> z;
		all.push_back(edge { u, v, z });
		if (!z)
			addBiEdge(u, v, c + 1, i, z);
		else
			addBiEdge(u, v, c, i, z);
	}
	Dijkstra();
	for (int i = tar; i != 1; i = prv[i])
		used[edg[i]] = 1;
	for (int i = 0; i < m; i++)
		if (used[i] ^ all[i].z)
			all[i].z = !all[i].z, ans.push_back(all[i]);
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i].u << " " << ans[i].v << " " << ans[i].z << endl;
	return 0;
}
