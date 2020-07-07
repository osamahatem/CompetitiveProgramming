/*
 * 598B. Queries on a String.cpp
 *
 *  Created on: Nov 13, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[10005], temp[10005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int m, l, r, k;
	scanf("%s%d", in, &m);
	int len = strlen(in) + 1;
	while (m--) {
		scanf("%d%d%d", &l, &r, &k);
		l--, r--;
		memcpy(temp, in, len * sizeof(char));
		for (int i = l; i <= r; i++) {
			int llen = r - l + 1;
			int npos = ((i - l + k) % llen) + l;
			temp[npos] = in[i];
		}
		memcpy(in, temp, len * sizeof(char));
	}
	printf("%s\n", in);
	return 0;
}
