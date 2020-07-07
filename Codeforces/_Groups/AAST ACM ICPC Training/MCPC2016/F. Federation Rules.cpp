/*
 * F. Federation Rules.cpp
 *
 *  Created on: Nov 5, 2016
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

	freopen("federation.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int x, y;
		char buff[5];
		scanf("%d%d%s", &x, &y, buff);
		bool flag = 0;
		if ((x < y && buff[0] == '<') || (x > y && buff[0] == '>'))
			flag = 1;
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
}
