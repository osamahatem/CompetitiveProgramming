/*
 * 676C. Vasya and String.cpp
 *
 *  Created on: May 25, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[100005];
int n, k;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%s", &n, &k, in);
	int cnt = 0, idx = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		while (idx < n && (cnt < k || (cnt == k && in[idx] != 'a')))
			cnt += in[idx++] == 'a';
		ans = max(ans, idx - i);
		cnt -= in[i] == 'a';
	}
	cnt = idx = 0;
	for (int i = 0; i < n; i++) {
		while (idx < n && (cnt < k || (cnt == k && in[idx] != 'b')))
			cnt += in[idx++] == 'b';
		ans = max(ans, idx - i);
		cnt -= in[i] == 'b';
	}
	printf("%d\n", ans);
	return 0;
}
