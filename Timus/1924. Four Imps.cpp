/*
 * 1924. Four Imps.cpp
 *
 *  Created on: Aug 6, 2014
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

	int n;
	scanf("%d", &n);
	n = n * (n + 1) / 2;
	printf("%s\n", ((n % 2) ? "grimy" : "black"));
	return 0;
}
