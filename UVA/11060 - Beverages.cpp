/*
 * 11060 - Beverages.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int T, n, m, deg[100];
char name[100][55], a[55], b[55];
vector<int> adj[100];

int getIdx(char s[]) {
	for (int i = 0; i < n; i++)
		if (!strcmp(name[i], s))
			return i;
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++)
			scanf("%s", name[i]), deg[i] = 0, adj[i].clear();
		scanf("%d", &m);
		while (m--) {
			scanf("%s%s", a, b);
			adj[getIdx(a)].push_back(getIdx(b));
			deg[getIdx(b)]++;
		}
		set<int> S;
		for (int i = 0; i < n; i++)
			if (!deg[i])
				S.insert(i);
		printf("Case #%d: Dilbert should drink beverages in this order:", ++T);
		while (S.size()) {
			int cur = *S.begin();
			S.erase(S.begin());
			printf(" %s", name[cur]);
			for (int i = 0; i < (int) adj[cur].size(); i++)
				if (--deg[adj[cur][i]] == 0)
					S.insert(adj[cur][i]);
		}
		printf(".\n\n");
	}
	return 0;
}
