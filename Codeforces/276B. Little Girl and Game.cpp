/*
 * 276B. Little Girl and Game.cpp
 *
 *  Created on: Jun 20, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[1005];
int cnt[26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", in);
	for (int i = 0; in[i]; i++)
		cnt[in[i] - 'a']++;
	int odd = 0;
	for (int i = 0; i < 26; i++)
		odd += cnt[i] & 1;
	printf("%s\n", (odd < 2 || (odd & 1) ? "First" : "Second"));
	return 0;
}
