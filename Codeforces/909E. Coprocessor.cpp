/*
 * 909E. Coprocessor.cpp
 *
 *  Created on: Dec 27, 2017
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56666
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int n, m, ty[MAXN], deg[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &ty[i]);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[b].push_back(a);
		deg[a]++;
	}
	queue<int> Q[2];
	for (int i = 0; i < n; i++)
		if (!deg[i])
			Q[ty[i]].push(i);
	int ans = 0;
	for (int q = (Q[0].empty() ? 1 : 0); Q[q].size(); q ^= 1) {
		ans += q;
		while (Q[q].size()) {
			int x = Q[q].front();
			Q[q].pop();
			for (auto ch : adj[x])
				if (--deg[ch] == 0)
					Q[ty[ch]].push(ch);
		}
	}
	printf("%d\n", ans);
	return 0;
}
