/*
 * 605B. Lazy Student.cpp
 *
 *  Created on: Dec 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

struct edge {
	int u, v, w, id, in;

	static const bool byW(const edge &a, const edge &b) {
		if (a.w != b.w)
			return a.w < b.w;
		return a.in > b.in;
	}

	static const bool byID(const edge &a, const edge &b) {
		return a.id < b.id;
	}
};

int N, M;
edge all[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &all[i].w, &all[i].in);
		all[i].id = i;
	}
	sort(all, all + M, edge::byW);
	int left = M - N + 1, u = 1;
	vector<pair<int, int>> edges;
	for (int i = 0; i < M; i++) {
		if (all[i].in) {
			all[i].u = u, all[i].v = u + 1;
			u++;
			for (int v = 1; left && v + 1 < u; left--, v++)
				edges.push_back(make_pair(v, u));
		} else {
			if (edges.empty()) {
				printf("-1\n");
				return 0;
			} else {
				all[i].u = edges.back().first, all[i].v = edges.back().second;
				edges.pop_back();
			}
		}
	}
	sort(all, all + M, edge::byID);
	for (int i = 0; i < M; i++)
		printf("%d %d\n", all[i].u, all[i].v);
	return 0;
}
