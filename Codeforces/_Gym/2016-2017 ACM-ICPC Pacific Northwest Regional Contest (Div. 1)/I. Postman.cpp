/*
 * I. Postman.cpp
 *
 *  Created on: Oct 10, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k;
vector<pair<int, int>> pos, neg;

long long solve(vector<pair<int, int>> vec) {
	int kk = 0;
	long long ret = 0;
	for (int i = (int) vec.size() - 1; ~i; i--) {
		if (kk) {
			int mini = min(vec[i].second, kk);
			vec[i].second -= mini, kk -= mini;
		}
		if (vec[i].second) {
			int trips = (vec[i].second + k - 1) / k;
			ret += 1ll * trips * vec[i].first * 2;
			kk = 1ll * trips * k - vec[i].second;
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	while (n--) {
		int x, m;
		scanf("%d%d", &x, &m);
		if (x >= 0)
			pos.push_back(make_pair(x, m));
		else
			neg.push_back(make_pair(-x, m));
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	long long ans = solve(pos) + solve(neg);
	printf("%lld\n", ans);
	return 0;
}
