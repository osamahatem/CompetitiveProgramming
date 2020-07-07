/*
 * 712A. Memory and Crow.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long arr[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	long long sum = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		arr[i] += sum;
		sum -= arr[i];
		sum *= -1;
	}
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%lld", arr[i]);
	}
	printf("\n");
	return 0;
}
