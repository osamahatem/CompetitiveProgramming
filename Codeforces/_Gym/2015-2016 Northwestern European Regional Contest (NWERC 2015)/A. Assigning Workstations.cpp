/*
 * A. Assigning Workstations.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;

int n, m;
pair<int, int> all[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &all[i].first, &all[i].second);
	sort(all, all + n);
	multiset<int> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (s.size() && *s.begin() + m < all[i].first)
			s.erase(s.begin());
		if (s.empty() || *s.begin() > all[i].first)
			ans++;
		else
			s.erase(s.begin());
		s.insert(all[i].first + all[i].second);
	}
	printf("%d\n", n - ans);
	return 0;
}
