/*
 * 459E. Pashmak and Graph.cpp
 *
 *  Created on: Aug 15, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;

struct edge {
	int u, v, w;

	const bool operator <(const edge &a) const {
		return w < a.w;
	}
};

edge all[MAXN];
int memo[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> all[i].u >> all[i].v >> all[i].w;
	sort(all, all + M);
	int ans = 0;
	vector<pair<int, int> > u;
	for (int i = 0; i < M; i++) {
		u.clear();
		int t = all[i].w;
		while (all[i].w == t) {
			u.push_back(make_pair(memo[all[i].u] + 1, all[i].v));
			i++;
		}
		i--;
		for (int j = 0; j < (int) u.size(); j++) {
			memo[u[j].second] = max(memo[u[j].second], u[j].first);
			ans = max(ans, memo[u[j].second]);
		}
	}
	cout << ans << "\n";
	return 0;
}
