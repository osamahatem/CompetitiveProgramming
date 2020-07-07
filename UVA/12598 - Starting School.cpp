/*
 * 12598 - Starting School.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct query {
	int id, val, ans;

	static const bool cmp(const query &a, const query &b) {
		return a.val < b.val;
	}

	static const bool cmp2(const query &a, const query &b) {
		return a.id < b.id;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case " << t << ":\n";
		int N, Q, K;
		cin >> N >> K >> Q;
		vector<int> pos(K);
		for (int i = 0; i < K; i++)
			cin >> pos[i];
		vector<query> all(Q);
		for (int i = 0; i < Q; i++) {
			cin >> all[i].val;
			all[i].id = i;
		}
		sort(all.begin(), all.end(), query::cmp);
		int idx = 0;
		while (idx < Q && all[idx].val <= K) {
			all[idx].ans = pos[all[idx].val - 1];
			idx++;
		}
		sort(pos.begin(), pos.end());
		int cur = 0, add = 0;
		while (idx < Q) {
			int tar = all[idx].val - K;
			if (cur >= K) {
				all[idx].ans = tar + add;
				idx++;
				continue;
			}
			if (pos[cur] <= tar + add) {
				add++;
				cur++;
				continue;
			}
			all[idx].ans = tar + add;
			idx++;
		}
		sort(all.begin(), all.end(), query::cmp2);
		for (int i = 0; i < Q; i++)
			cout << all[i].ans << "\n";
	}
	return 0;
}
