/*
 * 452 - Project Scheduling.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[50];
int cost[26], dp[26];
bool adj[26][26], valid[26];

int solve(int x) {
	int& ret = dp[x];
	if (~ret)
		return ret;
	ret = 0;
	for (int i = 0; i < 26; i++)
		if (adj[x][i])
			ret = max(ret, solve(i));
	ret += cost[x];
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	char* g;
	int T;
	scanf("%d", &T);
	gets(in);
	gets(in);
	while (T--) {
		memset(adj, 0, sizeof adj);
		memset(valid, 0, sizeof valid);
		memset(dp, -1, sizeof dp);
		while (g = gets(in), g != NULL && in[0]) {
			int x = 0, i;
			for (i = 2; in[i] && in[i] != ' '; i++)
				x = x * 10 + in[i] - '0';
			cost[in[0] - 'A'] = x, valid[in[0] - 'A'] = 1;
			i++;
			for (; in[i] && in[i - 1]; i++)
				adj[in[0] - 'A'][in[i] - 'A'] = 1;
		}
		int ans = 0;
		for (int i = 0; i < 26; i++)
			if (valid[i])
				ans = max(ans, solve(i));
		printf("%d\n", ans);
		if (T)
			printf("\n");
	}
	return 0;
}
