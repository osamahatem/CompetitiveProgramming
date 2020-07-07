/*
 * 454A. Little Pony and Crystal Mine.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	int mid = n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < abs(i - mid); j++)
			printf("*");
		for (int j = 0; j < n - 2 * abs(mid - i); j++)
			printf("D");
		for (int j = 0; j < abs(i - mid); j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
