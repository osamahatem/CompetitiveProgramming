/*
 * 387C. George and Number.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char str[100005];

int solve(int s, int e) {
	if (e == s)
		return 1;
	int idx = e;
	while (str[idx] == '0')
		idx--;
	if (!idx)
		return 1;
	idx = e;
	int mid = (s + e) / 2;
	while (str[idx] == '0')
		idx--;
	if (idx <= mid
			|| (e - idx + 1 == mid + 1
					&& string(str + s, mid + 1) < string(str + idx, e - idx + 1)))
		return 1;
	return solve(s, idx - 1) + solve(idx, e);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", str);
	printf("%d\n", solve(0, strlen(str) - 1));
	return 0;
}
