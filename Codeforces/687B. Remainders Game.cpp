/*
 * 687B. Remainders Game.cpp
 *
 *  Created on: Jun 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int cnt[MAXN], factor[MAXN];
bool prime[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(prime, 1, sizeof prime);
	for (int i = 2; i < MAXN; i++) {
		if (prime[i])
			for (int j = i; j < MAXN; j += i)
				prime[j] = 0, factor[j] = i;
	}
	int n, k;
	scanf("%d%d", &n, &k);
	while (n--) {
		int c, last = 0, cntt = 0;
		scanf("%d", &c);
		while (c > 1) {
			if (factor[c] != last) {
				cnt[last] = max(cnt[last], cntt);
				last = factor[c], cntt = 0;
			}
			cntt++;
			c /= factor[c];
		}
		cnt[last] = max(cnt[last], cntt);
	}
	bool ans = true;
	int last = 0, cntt = 0;
	while (k > 1) {
		if (factor[k] != last) {
			if (cntt > cnt[last])
				ans = false;
			last = factor[k], cntt = 0;
		}
		cntt++;
		k /= factor[k];
	}
	if (cntt > cnt[last])
		ans = false;
	printf("%s\n", ans ? "Yes" : "No");
	return 0;
}
