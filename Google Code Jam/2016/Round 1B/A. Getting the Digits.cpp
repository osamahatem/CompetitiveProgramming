/*
 * A. Getting the Digits.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[26], ans[10];
char in[2005];
string num[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN",
		"EIGHT", "NINE" };

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		memset(cnt, 0, sizeof cnt);
		scanf("%s", in);
		for (int i = 0; in[i]; i++)
			cnt[in[i] - 'A']++;

		ans[0] = cnt['Z' - 'A'];
		for (int i = 0; i < (int) num[0].size(); i++)
			cnt[num[0][i] - 'A'] -= ans[0];

		ans[2] = cnt['W' - 'A'];
		for (int i = 0; i < (int) num[2].size(); i++)
			cnt[num[2][i] - 'A'] -= ans[2];

		ans[4] = cnt['U' - 'A'];
		for (int i = 0; i < (int) num[4].size(); i++)
			cnt[num[4][i] - 'A'] -= ans[4];

		ans[6] = cnt['X' - 'A'];
		for (int i = 0; i < (int) num[6].size(); i++)
			cnt[num[6][i] - 'A'] -= ans[6];

		ans[8] = cnt['G' - 'A'];
		for (int i = 0; i < (int) num[8].size(); i++)
			cnt[num[8][i] - 'A'] -= ans[8];

		ans[3] = cnt['H' - 'A'];
		for (int i = 0; i < (int) num[3].size(); i++)
			cnt[num[3][i] - 'A'] -= ans[3];

		ans[1] = cnt['O' - 'A'];
		for (int i = 0; i < (int) num[1].size(); i++)
			cnt[num[1][i] - 'A'] -= ans[1];

		ans[5] = cnt['F' - 'A'];
		for (int i = 0; i < (int) num[5].size(); i++)
			cnt[num[5][i] - 'A'] -= ans[5];

		ans[7] = cnt['V' - 'A'];
		for (int i = 0; i < (int) num[7].size(); i++)
			cnt[num[7][i] - 'A'] -= ans[7];

		ans[9] = cnt['E' - 'A'];
		for (int i = 0; i < (int) num[9].size(); i++)
			cnt[num[9][i] - 'A'] -= ans[9];

		for (int i = 0; i < 10; i++)
			while (ans[i]--)
				printf("%d", i);
		printf("\n");
	}
	return 0;
}
