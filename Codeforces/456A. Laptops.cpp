/*
 * 456A. Laptops.cpp
 *
 *  Created on: Aug 8, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, b;
	vector<pair<int, int> > all;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &a, &b);
		all.push_back(make_pair(a, b));
	}
	sort(all.begin(), all.end());
	int maxi = all[0].second;
	bool flag = 0;
	for (int i = 1; i < (int) all.size(); i++) {
		if (maxi > all[i].second)
			flag = 1;
		maxi = max(maxi, all[i].second);
	}
	printf("%s Alex\n", (flag ? "Happy" : "Poor"));
	return 0;
}
