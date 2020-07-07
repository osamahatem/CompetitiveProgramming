/*
 * 4481 - Jingle Composing.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int val[256];
char in[205];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	val['W'] = 64, val['H'] = 32, val['Q'] = 16, val['E'] = 8;
	val['S'] = 4, val['T'] = 2, val['X'] = 1;
	while (scanf("%s", in), in[0] != '*') {
		int ans = 0, cnt = 0;
		for (int i = 0; in[i]; i++)
			if (in[i] == '/') {
				ans += cnt == 64;
				cnt = 0;
			} else
				cnt += val[in[i]];
		printf("%d\n", ans);
	}
	return 0;
}
