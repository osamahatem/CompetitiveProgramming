/*
 * 124 - Following Orders.cpp
 *
 *  Created on: Sep 30, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[250], out[25];
int deg[26], cnt, T;
bool val[26], adj[26][26], vis[26];

void solve(int idx, int len) {
	if (len == cnt) {
		printf("%s\n", out);
		return;
	}
	vis[idx] = 1;
	for (int i = 0; i < 26; i++)
		if (adj[idx][i])
			deg[i]--;
	for (int i = 0; i < 26; i++) {
		if (val[i] && !deg[i] && !vis[i]) {
			out[len] = 'a' + i;
			solve(i, len + 1);
		}
	}
	for (int i = 0; i < 26; i++)
		if (adj[idx][i])
			deg[i]++;
	vis[idx] = 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (gets(in) != NULL) {
		if (T++)
			printf("\n");
		int len = strlen(in);
		memset(val, 0, sizeof val), cnt = 0;
		for (int i = 0; i < len; i += 2) {
			val[in[i] - 'a'] = 1, deg[in[i] - 'a'] = 0;
			memset(adj[in[i] - 'a'], 0, sizeof adj[in[i] - 'a']);
			cnt++;
		}
		out[cnt] = 0;
		gets(in);
		len = strlen(in);
		for (int i = 0; i < len; i += 4)
			if (!adj[in[i] - 'a'][in[i + 2] - 'a'])
				adj[in[i] - 'a'][in[i + 2] - 'a'] = 1, deg[in[i + 2] - 'a']++;
		for (int i = 0; i < 26; i++) {
			if (val[i] && !deg[i]) {
				out[0] = 'a' + i;
				solve(i, 1);
			}
		}
	}
	return 0;
}
