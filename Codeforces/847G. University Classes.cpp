/*
 * 847G. University Classes.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[7];
char in[10];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, ans = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", in);
		for (int i = 0; i < 7; i++) {
			cnt[i] += (in[i] == '1');
			ans = max(ans, cnt[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
