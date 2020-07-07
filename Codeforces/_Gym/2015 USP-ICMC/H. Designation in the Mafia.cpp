/*
 * H. Designation in the Mafia.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cost[26][26];
char inn[1000005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			scanf("%d", &cost[i][j]);
	for (int k = 0; k < 26; k++)
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
	scanf("%s", inn);
	string in = string(inn);
	int sz = in.size();
	long long ans = 0;
	for (int i = 0; i < sz / 2; i++) {
		int a = in[i] - 'a', b = in[sz - i - 1] - 'a';
		if (a == b)
			continue;
		int temp = min(cost[a][b], cost[b][a]);
		for (int c = 0; c < 26; c++) {
			if (c == a || c == b)
				continue;
			temp = min(temp, cost[a][c] + cost[b][c]);
		}
		ans += temp;
	}
	printf("%I64d\n", ans);
	return 0;
}
