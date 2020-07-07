/*
 * E. Cupcakes.cpp
 *
 *  Created on: Oct 19, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN], n, k;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	int maxi = -1, idx = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > maxi)
			maxi = arr[i], idx = i;
	}
	long long s = idx, e = 0, minSum = n + maxi - 1, maxSum = 0;
	for (int i = 0; i < n; i++) {
		maxSum += arr[i];
		if (i < idx)
			e += arr[i];
	}
	while (s <= k) {
		if (k <= e) {
			printf("YES\n");
			return 0;
		}
		s += minSum, e += maxSum;
	}
	printf("KEK\n");
	return 0;
}
