/*
 * L. Chocolate.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char s[2005];
int sum[26][2005], vis[26], id;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

//	freopen("chocolate.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int m, len;
		scanf("%d%s", &m, s);
		memset(sum, 0, sizeof sum);
		for (int p = 0; s[p]; p++) {
			for (int i = 0; p - i >= 0 && s[p + i] && s[p - i] == s[p + i]; i++)
				sum[s[p - i] - 'a'][2 * i + 1]++;
			for (int i = 1;
					p - i + 1 >= 0 && s[p + i] && s[p - i + 1] == s[p + i]; i++)
				sum[s[p - i + 1] - 'a'][2 * i]++;
		}
		for (int j = 0; j < 26; j++)
			for (int i = 0; s[i]; i++)
				sum[j][i + 1] += sum[j][i];
		while (m--) {
			id++;
			int a, b, ans = 0;
			char k[30];
			scanf("%d%d%s", &a, &b, k);
			for (int i = 0; k[i]; i++)
				if (vis[k[i] - 'a'] != id) {
					vis[k[i] - 'a'] = id;
					ans += sum[k[i] - 'a'][b] - sum[k[i] - 'a'][a - 1];
				}
			printf("%d\n", ans);
		}
	}
	return 0;
}
