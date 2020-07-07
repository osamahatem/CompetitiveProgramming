/*
 * E. Mirror Rice Cake.cpp
 *
 *  Created on: May 7, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, w[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	sort(w, w + n);
	int ans = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++)
		if (sum < w[i])
			sum += w[i], ans++;
	printf("%d\n", ans);
	return 0;
}
