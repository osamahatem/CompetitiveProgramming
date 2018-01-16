/*
 * 3561 - Low Cost Air Travel.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: Osama Hatem
 */
 
/*
Use Disjkstra's algorithm to get the minimum cost. The state is the index of the
last city visited of the trip and the number of the current city. We try all
possible prefixes of all tickets and match them to remaining cities in the trip.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int idx, cur, cost, par_i, par_c, t;

	bool operator <(const node& rhs) const {
		if (cost != rhs.cost)
			return cost < rhs.cost;
		if (idx != rhs.idx)
			return idx < rhs.idx;
		return cur < rhs.cur;
	}
};

int n, sz, q, cost[22];
vector<int> tick[22], trip;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T = 0;
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			cin >> cost[i] >> sz;
			tick[i].resize(sz);
			for (int j = 0; j < sz; j++)
				cin >> tick[i][j];
		}
		++T;
		cin >> q;
		for (int t = 1; t <= q; t++) {
			cin >> sz;
			trip.resize(sz);
			for (int i = 0; i < sz; i++)
				cin >> trip[i];
			set<node> S;
			map<pair<int, int>, int> ans, used;
			map<pair<int, int>, pair<int, int>> prv;
			S.insert(node { 0, trip[0], 0, -1, -1, -1 });
			while (S.size()) {
				node st = *S.begin();
				S.erase(S.begin());
				if (ans.count(make_pair(st.idx, st.cur)))
					continue;
				ans[make_pair(st.idx, st.cur)] = st.cost;
				prv[make_pair(st.idx, st.cur)] = make_pair(st.par_i, st.par_c);
				used[make_pair(st.idx, st.cur)] = st.t;
				if (st.idx == sz - 1)
					break;
				for (int i = 0; i < n; i++) {
					if (tick[i][0] != st.cur)
						continue;
					int temp = st.idx;
					for (int j = 1; temp < sz - 1 && j < (int) tick[i].size();
							j++) {
						if (tick[i][j] == trip[temp + 1])
							temp++;
						S.insert(
								node { temp, tick[i][j], st.cost + cost[i],
										st.idx, st.cur, i });
					}
				}
			}
			cout << "Case " << T << ", Trip " << t << ": Cost = "
					<< ans[make_pair(sz - 1, trip[sz - 1])] << endl;
			cout << "  Tickets used:";
			vector<int> path;
			int idx = sz - 1, c = trip[sz - 1];
			while (idx != 0 || c != trip[0]) {
				path.push_back(used[make_pair(idx, c)]);
				pair<int, int> temp = prv[make_pair(idx, c)];
				idx = temp.first, c = temp.second;
			}
			reverse(path.begin(), path.end());
			for (auto x : path)
				cout << " " << x + 1;
			cout << endl;
		}
	}
	return 0;
}
