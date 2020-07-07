/*
 * J. Tshirts Colors.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

char in[MAXN];
int cnt[MAXN][26], tot[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("colors.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(cnt, 0, sizeof cnt);
		memset(tot, 0, sizeof tot);
		int n, k, q, x;
		char c;
		scanf("%d%d%d%s", &n, &k, &q, in);
		for (int i = 0; in[i]; i++)
			cnt[i % k][in[i] - 'a']++, tot[i % k]++;
		int val = 0;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < 26; j++)
				if (cnt[i][j] == tot[i])
					val++;
		while (q--) {
			scanf("%d%*c%c", &x, &c);
			int s = cnt[x % k][in[x] - 'a'] == tot[x % k];
			cnt[x % k][in[x] - 'a']--, cnt[x % k][c - 'a']++;
			in[x] = c;
			int e = cnt[x % k][c - 'a'] == tot[x % k];
			val += e - s;
			printf("%s\n", val == k ? "YES" : "NO");
		}
	}
	return 0;
}
