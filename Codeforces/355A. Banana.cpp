/*
 * 355A. Banana.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char s[1005];
int n, cnt[26];

bool check(int x) {
	int need = 0;
	for (int i = 0; i < 26; i++)
		need += (cnt[i] + x - 1) / x;
	return need <= n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s%d", s, &n);
	for (int i = 0; s[i]; i++)
		cnt[s[i] - 'a']++;
	int s = 1, e = 1001;
	while (s < e) {
		int mid = (s + e) / 2;
		if (check(mid))
			e = mid;
		else
			s = mid + 1;
	}
	s = (s == 1001 ? -1 : s);
	printf("%d\n", s);
	string ans;
	if (s != -1) {
		for (int i = 0; i < 26; i++) {
			int need = (cnt[i] + s - 1) / s;
			for (int j = 0; j < need; j++)
				ans += 'a' + i;
		}
		while ((int) ans.size() < n)
			ans += 'z';
		printf("%s\n", ans.c_str());
	}
	return 0;
}
