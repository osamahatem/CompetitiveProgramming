/*
 * 847C. Sum of Nestings.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;

int n, add[MAXN];
long long k;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++) {
		add[i] = min(1ll * i, k);
		k -= add[i];
	}
	string ans = "";
	int cur = 0;
	for (int i = 0; i < n; i++) {
		while (cur < add[i])
			ans += "(", cur++;
		while (cur > add[i])
			ans += ")", cur--;
		ans += "(", cur++;
	}
	while (cur > 0)
		ans += ")", cur--;
	if (k)
		ans = "Impossible";
	printf("%s\n", ans.c_str());
	return 0;
}
