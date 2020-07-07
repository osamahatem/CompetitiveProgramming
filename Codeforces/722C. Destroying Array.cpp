/*
 * 722C. Destroying Array.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, arr[100005];
long long sum[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}
	set<pair<int, int>> ranges;
	multiset<long long> sums;
	ranges.insert( { 1, n }), sums.insert(sum[n]);
	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d", &x);
		auto it = --ranges.lower_bound( { x + 1, 0 });
		int a = it->first, b = it->second;
		ranges.erase(it);
		long long s = sum[b] - sum[a - 1];
		sums.erase(sums.find(s));
		if (x - 1 >= a)
			ranges.insert( { a, x - 1 }), sums.insert(sum[x - 1] - sum[a - 1]);
		if (x + 1 <= b)
			ranges.insert( { x + 1, b }), sums.insert(sum[b] - sum[x]);
		printf("%lld\n", *sums.rbegin());
	}
	printf("0\n");
	return 0;
}
