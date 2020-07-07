/*
 * H. Smooth Developer.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

map<string, int> rnk;
vector<int> adj[MAXN];
string name[MAXN];
bool vis[MAXN];
int n, k, c;
char in[20];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("alaa.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%s%d", in, &c);
			name[i] = (string) in;
			rnk[(string) in] = i;
			adj[i].resize(c), vis[i] = 0;
			for (int cc = 0; cc < c; cc++) {
				scanf("%s", in);
				adj[i][cc] = rnk[(string) in];
			}
		}
		queue<int> Q;
		while (k--) {
			scanf("%s", in);
			Q.push(rnk[(string) in]);
			vis[rnk[(string) in]] = 1;
		}
		while (Q.size()) {
			int cur = Q.front();
			Q.pop();
			for (int i = 0; i < (int) adj[cur].size(); i++)
				if (!vis[adj[cur][i]]) {
					Q.push(adj[cur][i]);
					vis[adj[cur][i]] = 1;
				}
		}
		for (int i = 0; i < n; i++)
			if (vis[i])
				printf("%s\n", name[i].c_str());
	}
	return 0;
}
