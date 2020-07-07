/*
 * 894A. QAQ.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char str[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", str);
	int len = strlen(str), ans = 0;
	for (int i = 0; i < len; i++)
		for (int j = i + 1; j < len; j++)
			for (int k = j + 1; k < len; k++)
				ans += str[i] == 'Q' && str[j] == 'A' && str[k] == 'Q';
	printf("%d\n", ans);
	return 0;
}
