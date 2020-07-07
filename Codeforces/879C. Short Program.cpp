/*
 * 879C. Short Program.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, op;
char in[3];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	int a = 1023, o = 0, x = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s%d", in, &op);
		for (int b = 0; b < 10; b++) {
			if (in[0] == '&' && (op & (1 << b)) == 0)
				a &= ~(1 << b), o &= ~(1 << b), x &= ~(1 << b);
			else if (in[0] == '|' && (op & (1 << b)))
				a |= (1 << b), o |= (1 << b), x &= ~(1 << b);
			else if (in[0] == '^' && (op & (1 << b)))
				x ^= (1 << b);
		}
	}
	printf("3\n& %d\n| %d\n^ %d\n", a, o, x);
	return 0;
}
