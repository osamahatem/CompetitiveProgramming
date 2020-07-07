/*
 * C. Stickmen.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

vector<int> adj[205];
ll C[205][5];
bool conn[205][205];
int common[205][205];

ll comb(int n, int r) {
	if (n < r)
		return 0;
	if (C[n][r] != -1)
		return C[n][r];
	if (n == r)
		return 1;
	if (!r)
		return 1;
	if (r == 1)
		return n;
	return C[n][r] = (comb(n - 1, r - 1) + comb(n - 1, r)) % mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, a, b;
	memset(C, -1, sizeof C);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		conn[a][b] = conn[b][a] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = 0; k < n; k++)
				if (i != k && j != k) {
					if (conn[i][k] && conn[j][k]) {
						common[i][j]++;
						common[j][i]++;
					}
				}
	ll res = 0;
	for (int i = 0; i < n; i++)
		if (adj[i].size() >= 4) {
			int chest = i;
			for (int j = 0; j < adj[i].size(); j++) {
				int trunk = adj[i][j];
				if (adj[trunk].size() >= 3) {
					int com = common[chest][trunk];
					int s1 = adj[chest].size() - 1 - com;
					int s2 = adj[trunk].size() - 1 - com;
					ll temp = 0;
					for (int c1 = 0; c1 <= 3; c1++) {
						for (int c2 = 0; c2 <= 2; c2++) {
							temp = (temp
									+ comb(s1, c1) * comb(s2, c2) % mod
											* comb(com, 3 - c1) % mod
											* comb(com - 3 + c1, 2 - c2) % mod)
									% mod;
						}
					}
					res = (res + temp) % mod;
				}
			}
		}
	printf("%d\n", (int) res);
	return 0;
}
