/*
 * 4.LearningByExample.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct cow {
	int w;
	bool s;

	const bool operator <(const cow &a) const {
		return w < a.w;
	}
};

int main() {
//#ifndef ONLINE_JUDGE
	freopen("learning.in", "r", stdin);
	freopen("learning.out", "w", stdout);
//#endif

	int n, a, b, ans = 0;
	cow all[50005];
	string t;
	vector<pair<int, int> > rng;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> t >> all[i].w;
		if (t == "S")
			all[i].s = 1;
		else
			all[i].s = 0;
	}
	sort(all, all + n);
	if (a <= all[0].w) {
		if (all[0].s)
			ans += all[0].w - a + 1;
		a = all[0].w + 1;
	}
	if (b > all[n - 1].w) {
		if (all[n - 1].s)
			ans += b - all[n - 1].w;
		b = all[n - 1].w;
	}
	for (int i = 0; i + 1 < n; i++) {
		if (!all[i].s && !all[i + 1].s)
			continue;
		if (all[i].s && all[i + 1].s)
			rng.push_back(make_pair(all[i].w + 1, all[i + 1].w));
		else {
			int e, s;
			e = s = (all[i].w + all[i + 1].w) / 2;
			s++;
			if ((all[i].w + all[i + 1].w) % 2 == 0) {
				rng.push_back(make_pair(e, e));
				e--;
			}
			if (all[i].s)
				rng.push_back(make_pair(all[i].w + 1, e));
			else
				rng.push_back(make_pair(s, all[i + 1].w));
		}
	}
	sort(rng.begin(), rng.end());
	for (int i = 0; i < (int) rng.size(); i++)
		if (a <= rng[i].second && b >= rng[i].first)
			ans += min(b, rng[i].second) - max(a, rng[i].first) + 1;
	cout << ans << endl;
	return 0;
}
