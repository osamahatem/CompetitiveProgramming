/*
 * 2001. Mathematicians and Berries.cpp
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

	int a1, a2, a3, b1, b2, b3;
	scanf("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3);
	printf("%d %d\n", a1 - a3, b1 - b2);
	return 0;
}
