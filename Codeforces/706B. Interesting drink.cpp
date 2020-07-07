/*
 * 706B. Interesting drink.cpp
 *
 *  Created on: Aug 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, q, x, arr[100000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &x);
		int idx = upper_bound(arr, arr + n, x) - arr;
		printf("%d\n", idx);
	}
	return 0;
}
