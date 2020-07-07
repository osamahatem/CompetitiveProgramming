/*
 * K. Kitchen Combinatorics.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long lim = 1000000000000000000ll;

int cnt[1005];
vector<int> req[100];
bool no[100][100];
int vis[1005], id;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int r, s, m, d, n;
	scanf("%d%d%d%d%d", &r, &s, &m, &d, &n);
	for (int i = 0; i < r; i++)
		scanf("%d", &cnt[i]);
	for (int i = 0; i < s + m + d; i++) {
		int k;
		scanf("%d", &k);
		req[i].resize(k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &req[i][j]);
			req[i][j]--;
		}
	}
	while (n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--,y--;
		no[x][y] = no[y][x] = 1;
	}
	long long ans = 0;
	bool flag = 1;
	for (int i = 0; flag && i < s; i++) {
		for (int j = s; flag && j < s + m; j++) {
			for (int k = s + m; flag && k < s + m + d; k++) {
				if (no[i][j] || no[j][k] || no[i][k])
					continue;
				id++;
				for (auto x : req[i])
					vis[x] = id;
				for (auto x : req[j])
					vis[x] = id;
				for (auto x : req[k])
					vis[x] = id;
				long long temp = 1;
				for (int l = 0; l < r; l++) {
					if (vis[l] != id)
						continue;
					if (temp <= lim / cnt[l])
						temp *= cnt[l];
					else
						flag = 0;
				}
				if (ans + temp <= lim)
					ans += temp;
				else
					flag = 0;
			}
		}
	}
	if (flag)
		printf("%lld\n", ans);
	else
		printf("too many\n");
	return 0;
}
