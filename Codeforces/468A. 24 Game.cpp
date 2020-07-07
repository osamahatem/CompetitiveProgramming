/*
 * 468A. 24 Game.cpp
 *
 *  Created on: Aug 2, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

void solve4() {
	printf("4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24\n");
}

void solve5() {
	printf("5 * 4 = 20\n20 + 3 = 23\n23 + 2 = 25\n25 - 1 = 24\n");
}

void solve6() {
	printf("6 - 5 = 1\n1 - 1 = 0\n4 * 3 = 12\n12 * 2 = 24\n");
	printf("24 + 0 = 24\n");
}

void solve7() {
	printf("7 + 6 = 13\n13 + 3 = 16\n5 * 4 = 20\n20 * 2 = 40\n40 - 16 = 24\n");
	printf("24 * 1 = 24\n");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	if (n < 4) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int z = 0;
	while (n - 4 >= 4) {
		printf("%d - %d = 1\n%d - %d = 1\n1 - 1 = 0\n", n, n - 1, n - 2, n - 3);
		z++;
		n -= 4;
	}
	if (n == 7)
		solve7();
	if (n == 6)
		solve6();
	if (n == 5)
		solve5();
	if (n == 4)
		solve4();
	while (z--)
		printf("24 + 0 = 24\n");
	return 0;
}
