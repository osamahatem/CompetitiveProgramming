/*
 * G. Genealogy.cpp
 *
 *  Created on: Oct 4, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int n, r;
int head[MAXN], nxt[MAXN], to[MAXN], last;
char son[15], father[15], fam[15];
map<pair<string, string>, int> rnk;
bool cycle[MAXN];
int vis[MAXN], cycleSZ[MAXN], deg[MAXN];
vector<int> temp;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

bool getCycle(int idx) {
	vis[idx] = 1;
	for (int i = head[idx]; i != -1; i = nxt[i]) {
		if ((!vis[to[i]] && getCycle(to[i])) || (vis[to[i]] == 1)) {
			cycle[idx] = 1, vis[idx] = 2;
			temp.push_back(idx);
			return true;
		}
	}
	vis[idx] = 2;
	return false;
}

int solve(int idx) {
	int ret = 0;
	for (int i = head[idx]; i != -1; i = nxt[i]) {
		if (!cycle[to[i]])
			ret = max(ret, 1 + solve(to[i]));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s%*s%*s%s", fam, son, father);
		if (!rnk.count( { fam, son }))
			rnk[ { fam, son }] = r++;
		if (!rnk.count( { fam, father }))
			rnk[ { fam, father }] = r++;
		addEdge(rnk[ { fam, father }], rnk[ { fam, son }]);
		deg[rnk[ { fam, son }]]++;
	}
	for (int i = 0; i < r; i++) {
		if (!vis[i]) {
			temp.clear();
			getCycle(i);
			if (temp.size()) {
				int sz = temp.size();
				for (int j = 0; j < (int) temp.size(); j++)
					cycleSZ[temp[j]] = sz;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < r; i++)
		if (cycle[i] || !deg[i])
			ans = max(ans, cycleSZ[i] + solve(i));
	printf("%d\n", ans);
	return 0;
}
