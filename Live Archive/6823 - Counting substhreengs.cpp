/*
 * 6823 - Counting substhreengs.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[1000005];
int cnt[3];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%s", in) != EOF) {
		cnt[1] = cnt[2] = 0;
		cnt[0] = 1;
		long long ans = 0;
		int mod = 0;
		for (int i = 0; in[i]; i++) {
			if (!isdigit(in[i])) {
				cnt[1] = cnt[2] = mod = 0;
				cnt[0] = 1;
				continue;
			}
			mod = (mod * 10 + in[i] - '0') % 3;
			ans += cnt[mod];
			cnt[mod]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
