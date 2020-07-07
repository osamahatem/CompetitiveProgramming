/*
 * 690D1. The Wall (easy).cpp
 *
 *  Created on: Jul 10, 2016
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

	int r, c;
	char in[105];
	scanf("%d%d", &r, &c);
	while (r--)
		scanf("%s", in);
	int ans = 0;
	for (int i = 0; i < c; i++)
		ans += (in[i] == 'B' && (!i || in[i - 1] == '.'));
	printf("%d\n", ans);
	return 0;
}
