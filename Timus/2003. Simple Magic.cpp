/*
 * 2003. Simple Magic.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<int,int> cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, arr[10005], c = 1;
	bool flag = 1, allOnes = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 1)
			continue;
		allOnes = 0;
		for (int j = 2; j <= arr[i] / j; j++) {
			if (arr[i] % j == 0) {
				cnt[j]++;
				if (cnt[j] == 2)
					c = 2;
				if (cnt[j] > 2) {
					flag = 0;
					break;
				}
				while (arr[i] % j == 0)
					arr[i] /= j;
			}
		}
		if (arr[i] > 1) {
			int j = arr[i];
			cnt[j]++;
			if (cnt[j] == 2)
				c = 2;
			if (cnt[j] > 2) {
				flag = 0;
				break;
			}
		}
		if (!flag)
			break;
	}
	if (flag)
		printf("%d\n", (allOnes ? 0 : c));
	else
		printf("infinity\n");
	return 0;
}
