/*
 * 6822 - Black and white stones.cpp
 *
 *  Created on: Sep 19, 2015
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

	int a, b;
	char in[5005];
	while (scanf("%d%d%s", &a, &b, in) != EOF) {
		long long ans = 0;
		int Bcnt = 0;
		for (int i = 0; in[i]; i++)
			Bcnt += in[i] == 'B';
		for (int i = Bcnt - 1; i >= 0; i--) {
			if (in[i] == 'B')
				continue;
			while (in[Bcnt] == 'W')
				Bcnt++;
			ans += min(1ll * a, 1ll * (Bcnt - i) * (a - b));
			Bcnt++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
