/*
 * B. Pen Pineapple Apple Pen.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char buff[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", buff);
		int sz = strlen(buff);
		if (sz == 1) {
			printf("YES\n");
		} else if (sz != (sz & -sz)) {
			printf("NO\n");
		} else {
			bool valid = 1;
			for (int i = 0; i < sz - 1; i += 2) {
				if (buff[i] != 'P' && buff[i + 1] != 'P')
					valid = false;
			}
			if (valid)
				printf("YES\n");
			else
				printf("NO\n");
		}

	}
	return 0;
}
