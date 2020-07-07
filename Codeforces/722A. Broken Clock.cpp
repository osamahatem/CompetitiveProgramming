/*
 * 722A. Broken Clock.cpp
 *
 *  Created on: Oct 1, 2016
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

	int t, h, m;
	scanf("%d%d:%d", &t, &h, &m);
	if (m > 59)
		m %= 10;
	if ((t == 24 && h > 23) || (t == 12 && h > 12 && h % 10))
		h %= 10;
	if (t == 12 && !(h % 10))
		h = 10;
	printf("%02d:%02d\n", h, m);
	return 0;
}
