/*
 * D. Decoding of Varints.cpp
 *
 *  Created on: Nov 14, 2017
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
	int x;
	unsigned long long off = 1, temp = 0;
	while (n--) {
		scanf("%d", &x);
		if (x & 128) {
			x -= 128;
			temp += off * x;
			off <<= 7;
		} else {
			temp += off * x;
			off = 1;
			if (temp % 2)
				printf("-%llu\n", temp / 2 + 1);
			else
				printf("%llu\n", temp / 2);
			temp = 0;
		}
	}
	return 0;
}
