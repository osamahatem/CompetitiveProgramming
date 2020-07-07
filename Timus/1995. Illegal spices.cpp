/*
 * 1995. Illegal spices.cpp
 *
 *  Created on: Aug 4, 2014
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

	int n, k, p;
	vector<int> all;
	scanf("%d%d%d", &n, &k, &p);
	int lighter = n - k;
	long long sum = 0;
	for (int i = 0; i < n - k; i++) {
		all.push_back(1);
		sum++;
	}
	int cur = 2;
	for (int i = 0; i < k; i++) {
		if (lighter * 100 >= p * (n - k + i)) {
			sum += cur;
			all.push_back(cur);
		} else {
			cur++;
			lighter = n - k + i;
			i--;
		}
	}
	printf("%lld\n%d", sum, all[0]);
	for (int i = 1; i < (int) all.size(); i++)
		printf(" %d", all[i]);
	printf("\n");
	return 0;
}
