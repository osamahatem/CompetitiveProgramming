/*
 * 462B. Appleman and Card Game.cpp
 *
 *  Created on: Jun 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[100005];
int cnt[26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k;
	scanf("%d%d%s", &n, &k, in);
	for (int i = 0; i < n; i++)
		cnt[in[i] - 'A']++;
	sort(cnt, cnt + 26, greater<int>());
	long long ans = 0;
	for (int i = 0; i < 26 && k; i++) {
		int add = min(k, cnt[i]);
		ans += 1ll * add * add;
		k -= add;
	}
	printf("%lld\n", ans);
	return 0;
}
