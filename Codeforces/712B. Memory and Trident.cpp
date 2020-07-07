/*
 * 712B. Memory and Trident.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char S[100005];
map<char, int> cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", S);
	for (int i = 0; S[i]; i++)
		cnt[S[i]]++;
	int ans = 0;
	int mini = min(cnt['U'], cnt['D']);
	cnt['U'] -= mini, cnt['D'] -= mini;
	mini = min(cnt['R'], cnt['L']);
	cnt['R'] -= mini, cnt['L'] -= mini;
	if ((cnt['U'] + cnt['D'] + cnt['R'] + cnt['L']) % 2)
		ans = -1;
	else
		ans = (cnt['U'] + cnt['D'] + cnt['R'] + cnt['L']) / 2;
	printf("%d\n", ans);
	return 0;
}
