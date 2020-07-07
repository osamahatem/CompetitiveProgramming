/*
 * H. Zig Zag Nametag.cpp
 *
 *  Created on: Aug 31, 2016
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

	int k;
	scanf("%d", &k);
	int len = (k + 24) / 25;
	string ans = "a";
	for (int i = 0; i < len; i++) {
		int last = ans.back() - 'a';
		for (int let = 0; let < 26; let++) {
			int maxi = abs(let - last);
			if (i + 1 < len)
				maxi += max(let, 25 - let);
			if (i + 2 < len)
				maxi += 25 * (len - i - 2);
			if (maxi >= k) {
				ans += 'a' + let;
				k -= abs(let - last);
				break;
			}
		}
	}
	if (k < 0) {
		int dir = (ans[len] < ans[len - 1] ? 1 : -1);
		while (k < 0)
			ans[len] += dir, k++;
	}
	printf("%s\n", ans.c_str());
	return 0;
}
