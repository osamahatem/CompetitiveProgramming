/*
 * 223B. Two Strings.cpp
 *
 *  Created on: Apr 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char s[200005], t[200005];
int maxEnd[200005], maxStart[200005], last[26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s%s", s, t);
	memset(last, -1, sizeof last);
	int idx = 0, ls = strlen(s), lt = strlen(t);
	for (int i = 0; s[i]; i++) {
		if (idx < lt && s[i] == t[idx])
			last[s[i] - 'a'] = idx++;
		maxEnd[i] = last[s[i] - 'a'] + 1;
	}
	idx = lt - 1;
	fill(last, last + 26, lt);
	for (int i = ls - 1; i >= 0; i--) {
		if (idx >= 0 && s[i] == t[idx])
			last[s[i] - 'a'] = idx--;
		maxStart[i] = lt - last[s[i] - 'a'];
	}
	for (int i = 0; s[i]; i++)
		if (maxEnd[i] + maxStart[i] - 1 < lt) {
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	return 0;
}
