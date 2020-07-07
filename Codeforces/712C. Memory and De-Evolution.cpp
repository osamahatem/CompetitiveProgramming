/*
 * 712C. Memory and De-Evolution.cpp
 *
 *  Created on: Sep 10, 2016
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

	int x, y;
	scanf("%d%d", &x, &y);
	int arr[] = { y, y, y }, ans = 0;
	while (arr[0] < x) {
		arr[0] = arr[1] + arr[2] - 1;
		arr[0] = min(arr[0], x);
		sort(arr, arr + 3);
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
