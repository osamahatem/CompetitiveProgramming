/*
 * 879A. Borya's Diagnosis.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, s[1005], d[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &s[i], &d[i]);
	int idx = 0, ans = 0;
	while (idx < n) {
		ans++;
		if (ans >= s[idx] && (ans - s[idx]) % d[idx] == 0)
			idx++;
	}
	printf("%d\n", ans);
	return 0;
}
