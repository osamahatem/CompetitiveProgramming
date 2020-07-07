/*
 * E. My Friend of Misery.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int am[MAXN], n;
bool ac[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("friends.in", "r", stdin);
	int T;
	char c;
	scanf("%d", &T);
	while (T--) {
		long long maxi = 1ll << 60, mini = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%*c%c", &am[i], &c);
			ac[i] = (c == '+' ? 1 : 0);
			if (ac[i])
				mini += am[i] + 25;
		}
		for (int i = 0; i < n; i++) {
			if (ac[i])
				mini -= am[i] + 25;
			else
				maxi = min(maxi, am[i] + 25 - mini);
		}
		printf("%I64d\n", maxi);
	}
	return 0;
}
