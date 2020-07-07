/*
 * 4942. Integer Factorization (15 digits).cpp
 *
 *  Created on: Oct 30, 2014
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

	long long x;
	while (scanf("%lld", &x), x) {
		bool sp = 0;
		for (long long i = 2; i * i <= x; i++) {
			int c = 0;
			while (x % i == 0) {
				x /= i;
				c++;
			}
			if (c) {
				if (sp)
					printf(" ");
				printf("%lld^%d", i, c);
				sp = 1;
			}
		}
		if (x > 1) {
			if (sp)
				printf(" ");
			printf("%lld^1", x);
		}
		printf("\n");
	}
	return 0;
}
