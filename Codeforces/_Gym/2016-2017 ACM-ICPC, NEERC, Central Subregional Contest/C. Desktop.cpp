/*
 * C. Desktop.cpp
 *
 *  Created on: Oct 19, 2017
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

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int h, w;
	scanf("%d%d", &h, &w);
	if (h < 2 || w < 2) {
		printf("0\n");
		return 0;
	}
	int ans = h * w / 2 - 1;
	printf("%d\n", ans);
	if (h & 1) {
		for (int i = 1; i + 1 <= w; i += 2)
			printf("%d %d\n", h - 1, i);
		h--;
	}
	for (int i = 1; i + 1 <= h; i += 2)
		for (int j = 1; j + 2 <= w; j++)
			printf("%d %d\n", i, j);
	for (int i = 1; i + 1 <= h; i++)
		printf("%d %d\n", i, w - 1);
	return 0;
}
