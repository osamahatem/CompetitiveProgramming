/*
 * 551E. GukiZ and GukiZiana.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int GROUP_SIZE = 708;

vector<vector<pair<long long, int>>> groups;
long long increase[GROUP_SIZE];
int N;

void update(int l, int r, int val) {
	for (int g = 0; g < (int) groups.size(); g++) {
		int gs = g * GROUP_SIZE, ge = gs + (int) groups[g].size() - 1;
		if (gs >= l && ge <= r)
			increase[g] += val;
		else if (gs <= r && ge >= l) {
			for (int i = 0; i < (int) groups[g].size(); i++)
				if (groups[g][i].second >= l && groups[g][i].second <= r)
					groups[g][i].first += val;
			sort(groups[g].begin(), groups[g].end());
		}
	}
}

int query(int val) {
	int mini = N, maxi = -1, idx;
	long long nval;
	for (int g = 0; g < (int) groups.size(); g++) {
		nval = val - increase[g];
		idx = lower_bound(groups[g].begin(), groups[g].end(),
				make_pair(nval, 0)) - groups[g].begin();
		if (idx < (int) groups[g].size() && groups[g][idx].first == nval)
			mini = min(mini, groups[g][idx].second);
		idx = upper_bound(groups[g].begin(), groups[g].end(),
				make_pair(nval, N)) - groups[g].begin() - 1;
		if (idx >= 0 && groups[g][idx].first == nval)
			maxi = max(maxi, groups[g][idx].second);
	}
	return (maxi == -1 ? maxi : maxi - mini);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int Q, t, l, r, x;
	scanf("%d%d", &N, &Q);
	vector<pair<long long, int>> cur_group;
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		cur_group.push_back(make_pair(x, i));
		if (cur_group.size() == GROUP_SIZE || i == N - 1) {
			sort(cur_group.begin(), cur_group.end());
			groups.push_back(cur_group);
			cur_group.clear();
		}
	}
	while (Q--) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d", &l, &r, &x);
			update(l - 1, r - 1, x);
		} else {
			scanf("%d", &x);
			cout << query(x) << endl;
		}
	}
	return 0;
}
