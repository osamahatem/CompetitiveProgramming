/*
 * 624E. Electric Charges.cpp
 *
 *  Created on: Mar 24, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int minPrefix[MAXN], minSuffix[MAXN];
int maxPrefix[MAXN], maxSuffix[MAXN];
int n;
vector<pair<int, int>> all;

long long distSq(int x1, int y1, int x2, int y2) {
	int dx = x1 - x2, dy = y2 - y1;
	return 1ll * dx * dx + 1ll * dy * dy;
}

bool check(long long dist) {
	if (distSq(all[0].first, 0, all[n - 1].first, 0) <= dist)
		return true;
	if (distSq(0, minPrefix[n - 1], 0, maxPrefix[n - 1]) <= dist)
		return true;
	int s = 0, e = 0, m = n - 1;
	while (s < n && all[s].first <= 0) {
		while (all[m].first > -all[s].first)
			m--;
		while (e < s
				|| (e < n && distSq(all[s].first, 0, all[e].first, 0) <= dist))
			e++;
		e--;
		int minY, maxY, rb = min(m, e);
		if (s && rb + 1 < n) {
			minY = min(minPrefix[s - 1], minSuffix[rb + 1]);
			maxY = max(maxPrefix[s - 1], maxSuffix[rb + 1]);
		} else if (s)
			minY = minPrefix[s - 1], maxY = maxPrefix[s - 1];
		else
			minY = minSuffix[rb + 1], maxY = maxSuffix[rb + 1];
		long long temp = distSq(0, minY, 0, maxY);
		temp = max(temp, distSq(0, maxY, all[s].first, 0));
		temp = max(temp, distSq(0, minY, all[s].first, 0));
		if (temp <= dist)
			return true;
		s++;
	}
	s = n - 1, m = 0, e = n - 1;
	while (s >= 0 && all[s].first > 0) {
		while (-all[m].first > all[s].first)
			m++;
		while (e > s
				|| (e >= 0 && distSq(all[s].first, 0, all[e].first, 0) <= dist))
			e--;
		e++;
		int minY, maxY, lb = max(m, e);
		if (lb && s + 1 < n) {
			minY = min(minPrefix[lb - 1], minSuffix[s + 1]);
			maxY = max(maxPrefix[lb - 1], maxSuffix[s + 1]);
		} else if (lb)
			minY = minPrefix[lb - 1], maxY = maxPrefix[lb - 1];
		else
			minY = minSuffix[s + 1], maxY = maxSuffix[s + 1];
		long long temp = distSq(0, minY, 0, maxY);
		temp = max(temp, distSq(0, maxY, all[s].first, 0));
		temp = max(temp, distSq(0, minY, all[s].first, 0));
		if (temp <= dist)
			return true;
		s--;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	all.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &all[i].first, &all[i].second);

	sort(all.begin(), all.end());
	minPrefix[0] = maxPrefix[0] = all[0].second;
	for (int i = 1; i < n; i++) {
		minPrefix[i] = min(all[i].second, minPrefix[i - 1]);
		maxPrefix[i] = max(all[i].second, maxPrefix[i - 1]);
	}
	minSuffix[n - 1] = maxSuffix[n - 1] = all[n - 1].second;
	for (int i = n - 2; i >= 0; i--) {
		minSuffix[i] = min(all[i].second, minSuffix[i + 1]);
		maxSuffix[i] = max(all[i].second, maxSuffix[i + 1]);
	}

	long long s = 0, e = 1ll << 60;
	while (s < e) {
		long long mid = (s + e) / 2;
		if (check(mid))
			e = mid;
		else
			s = mid + 1;
	}
	printf("%lld\n", s);
	return 0;
}
