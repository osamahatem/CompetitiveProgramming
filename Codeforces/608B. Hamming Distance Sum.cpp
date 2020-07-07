/*
 * 608B. Hamming Distance Sum.cpp
 *
 *  Created on: Dec 23, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

char a[MAXN], b[MAXN];
int sum[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s%s", a, b);
	int la = strlen(a), lb = strlen(b);
	for (int i = 0; i < la; i++)
		sum[i] = (i ? sum[i - 1] : 0) + (a[i] == '1');
	long long ans = 0;
	for (int i = 0; i < lb; i++) {
		int s = max(0, la - (lb - i));
		int e = min(la - 1, i);
		int oSum = sum[e] - (s ? sum[s - 1] : 0);
		if (b[i] == '1')
			ans += e - s + 1 - oSum;
		else
			ans += oSum;
	}
	printf("%lld\n", ans);
	return 0;
}
