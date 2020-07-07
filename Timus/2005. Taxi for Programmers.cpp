/*
 * 2005. Taxi for Programmers.cpp
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

	int cost[5][5], arr[] = { 0, 1, 2, 3, 4 };
	int ans[5], mini = (int) 1e7;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &cost[i][j]);
	do {
		if (arr[3] == 2)
			continue;
		int temp = 0;
		for (int i = 1; i < 5; i++)
			temp += cost[arr[i - 1]][arr[i]];
		if (temp < mini) {
			mini = temp;
			for (int i = 0; i < 5; i++)
				ans[i] = arr[i] + 1;
		}
	} while (next_permutation(arr + 1, arr + 4));
	printf("%d\n%d", mini, ans[0]);
	for (int i = 1; i < 5; i++)
		printf(" %d", ans[i]);
	printf("\n");
	return 0;
}
