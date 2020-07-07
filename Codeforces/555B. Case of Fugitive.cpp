/*
 * 555B. Case of Fugitive.cpp
 *
 *  Created on: Jun 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

struct gap {
	long long diff, lim;
	int s, e, id, bridge;

	static bool byS(const gap &a, const gap &b) {
		return a.s < b.s;
	}

	static bool byID(const gap &a, const gap &b) {
		return a.id < b.id;
	}
};

gap gaps[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<pair<long long, long long>> isl(n);
	vector<pair<long long, int>> br(m);
	for (int i = 0; i < n; i++)
		cin >> isl[i].first >> isl[i].second;
	for (int i = 0; i < m; i++) {
		cin >> br[i].first;
		br[i].second = i + 1;
	}
	sort(br.begin(), br.end());
	for (int i = 1; i < n; i++) {
		gaps[i - 1].id = i;
		gaps[i - 1].diff = isl[i].first - isl[i - 1].second;
		gaps[i - 1].lim = isl[i].second - isl[i - 1].first;
		gaps[i - 1].s = lower_bound(br.begin(), br.end(),
				make_pair(gaps[i - 1].diff, 0)) - br.begin();
		gaps[i - 1].e = upper_bound(br.begin(), br.end(),
				make_pair(gaps[i - 1].lim, m)) - br.begin() - 1;
	}
	sort(gaps, gaps + n - 1, gap::byS);
	int cur_gap = 0, ans = 0;
	set<pair<int, int>> cur_ends;
	for (int i = 0; i < m; i++) {
		while (cur_gap + 1 < n && gaps[cur_gap].s <= i) {
			cur_ends.insert(make_pair(gaps[cur_gap].e, cur_gap));
			cur_gap++;
		}
		if (!cur_ends.size()) {
			if (cur_gap + 1 == n)
				break;
			continue;
		}
		if (cur_ends.begin()->first < i) {
			cout << "No" << endl;
			return 0;
		}
		gaps[cur_ends.begin()->second].bridge = br[i].second;
		cur_ends.erase(cur_ends.begin());
		ans++;
	}
	if (ans + 1 < n) {
		cout << "No" << endl;
		return 0;
	}
	sort(gaps, gaps + n - 1, gap::byID);
	cout << "Yes" << endl;
	for (int i = 0; i + 1 < n; i++) {
		if (i)
			cout << " ";
		cout << gaps[i].bridge;
	}
	cout << endl;
	return 0;
}
