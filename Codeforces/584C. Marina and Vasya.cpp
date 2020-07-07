/*
 * 584C. Marina and Vasya.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

char a[MAXN], b[MAXN], ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, t, ta = 0, tb = 0;
	scanf("%d%d%s%s", &n, &t, a, b);
	ans[n] = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == b[i])
			ans[i] = b[i];
		else if (ta <= tb)
			ans[i] = b[i], ta++;
		else
			ans[i] = a[i], tb++;
	for (int i = 0; i < n && ta < t && tb < t; i++) {
		if (a[i] == b[i])
			ta++, tb++, ans[i]++;
		if (ans[i] > 'z')
			ans[i] = 'a';
	}
	for (int i = 0; i < n && ta < t; i++)
		if (a[i] != b[i] && ans[i] == a[i]) {
			ta++;
			for (int j = 0; j < 3; j++)
				if (a[i] != 'a' + j && b[i] != 'a' + j) {
					ans[i] = 'a' + j;
					break;
				}
		}
	for (int i = 0; i < n && tb < t; i++)
		if (a[i] != b[i] && ans[i] == b[i]) {
			tb++;
			for (int j = 0; j < 3; j++)
				if (a[i] != 'a' + j && b[i] != 'a' + j) {
					ans[i] = 'a' + j;
					break;
				}
		}
	if (ta == t && tb == t)
		printf("%s\n", ans);
	else
		printf("-1\n");
	return 0;
}
