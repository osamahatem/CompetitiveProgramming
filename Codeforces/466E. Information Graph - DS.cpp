/*
 * 466E. Information Graph - DS.cpp
 *
 *  Created on: Jun 23, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

struct DisjointSet {
	vector<int> root, rank;

	DisjointSet(int n) {
		for (int i = 0; i < n; i++) {
			root.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int n) {
		return (root[n] == n ? root[n] : root[n] = find(root[n]));
	}

	bool merge(int a, int b) {
		int sa = find(a);
		int sb = find(b);
		if (sa == sb)
			return false;
		if (rank[sa] < rank[sb])
			root[sa] = root[sb];
		else
			root[sb] = root[sa];
		if (rank[sa] == rank[sb])
			rank[sa]++;
		return true;
	}
};

struct input {
	int t, x, y;
};

struct query {
	int t, emp, doc;bool ans;

	static bool byTime(const query &a, const query &b) {
		return a.t < b.t;
	}

	static bool byDoc(const query &a, const query &b) {
		return a.doc < b.doc;
	}
};

int head[MAXN], nxt[MAXN], to[MAXN], cost[MAXN], deg[MAXN], last;
int docEmployee[MAXN], docs;
int in[MAXN], out[MAXN], timer;

void addEdge(int f, int t, int c) {
	to[last] = t;
	cost[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
	deg[t]++;
}

void DFS(int cur) {
	in[cur] = timer++;
	for (int i = head[cur]; i != -1; i = nxt[i])
		DFS(to[i]);
	out[cur] = timer++;
}

inline bool isParent(int u, int v) {
	return (in[v] <= in[u] && out[v] >= out[u]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	int n, m, t, x, y;
	vector<query> queries;
	vector<input> all;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &t, &x);
		if (t == 1) {
			scanf("%d", &y);
			addEdge(y, x, i);
		} else if (t == 2) {
			docEmployee[++docs] = x;
		} else {
			scanf("%d", &y);
			queries.push_back(query { i, x, y });
		}
		all.push_back(input { t, x, y });
	}
	for (int i = 1; i <= n; i++)
		if (!deg[i])
			DFS(i);
	sort(queries.begin(), queries.end(), query::byDoc);
	int cur_query = 0, cur_doc = 0;
	DisjointSet DS(n + 1);
	for (int i = 0; i < m; i++) {
		if (all[i].t == 1)
			DS.merge(all[i].x, all[i].y);
		else if (all[i].t == 2) {
			++cur_doc;
			while (cur_query < (int) queries.size()
					&& queries[cur_query].doc == cur_doc) {
				int s_emp = docEmployee[cur_doc];
				int t_emp = queries[cur_query].emp;
				bool par = isParent(s_emp, t_emp);
				bool conn = DS.find(s_emp) == DS.find(t_emp);
				queries[cur_query].ans = par && conn;
				cur_query++;
			}
		}
	}
	sort(queries.begin(), queries.end(), query::byTime);
	for (int i = 0; i < (int) queries.size(); i++)
		if (queries[i].ans)
			printf("YES\n");
		else
			printf("NO\n");
	return 0;
}
