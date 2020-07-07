/*
 * 583C. GCD Table.cpp
 *
 *  Created on: Oct 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int ans[505];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x;
	multiset<int, greater<int>> all;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			all.insert(x);
		}
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%d", *(all.begin()));
		ans[i] = *(all.begin());
		all.erase(all.begin());
		for (int j = 0; j < i; j++) {
			int g = __gcd(ans[j], ans[i]);
			all.erase(all.find(g));
			all.erase(all.find(g));
		}
	}
	printf("\n");
	return 0;
}
