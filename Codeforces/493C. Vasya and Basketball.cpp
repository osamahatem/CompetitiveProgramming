/*
 * 493C. Vasya and Basketball.cpp
 *
 *  Created on: Dec 3, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct shot {
	int d, t;

	const bool operator <(const shot &a) const {
		return d < a.d;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, d, s1, s2;
	vector<shot> all;
	cin >> n;
	s1 = n * 3;
	while (n--) {
		cin >> d;
		all.push_back(shot { d, 0 });
	}
	cin >> m;
	s2 = m * 3;
	while (m--) {
		cin >> d;
		all.push_back(shot { d, 1 });
	}
	sort(all.begin(), all.end());
	int maxi = s1 - s2, ms1 = s1, ms2 = s2;
	for (int i = 0; i < (int) all.size(); i++) {
		int j = i;
		while (j < (int) all.size() && all[j].d == all[i].d) {
			if (all[j].t)
				s2--;
			else
				s1--;
			j++;
		}
		i = j - 1;
		if (s1 - s2 > maxi || (s1 - s2 == maxi && s1 > ms1))
			maxi = s1 - s2, ms1 = s1, ms2 = s2;
	}
	cout << ms1 << ":" << ms2 << endl;
	return 0;
}
