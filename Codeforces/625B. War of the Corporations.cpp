/*
 * 625B. War of the Corporations.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char sa[100005], sb[35];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s%s", sa, sb);
	int ans = 0;
	for (int i = 0; sa[i]; i++) {
		int j;
		for (j = 0; sb[j] && sa[i + j]; j++)
			if (sa[i + j] != sb[j])
				break;
		if (!sb[j])
			ans++, i += j - 1;
	}
	printf("%d\n", ans);
	return 0;
}
