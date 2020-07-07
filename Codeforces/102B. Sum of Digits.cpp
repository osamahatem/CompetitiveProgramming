/*
 * 102B. Sum of Digits.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char str[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", str);
	int x = 0, ans = 0;
	for (int i = 0; str[i]; i++)
		x += str[i] - '0';
	while (x > 9) {
		int temp = 0;
		while (x) {
			temp += x % 10;
			x /= 10;
		}
		x = temp;
		ans++;
	}
	if (str[1])
		ans++;
	printf("%d\n", ans);
	return 0;
}
