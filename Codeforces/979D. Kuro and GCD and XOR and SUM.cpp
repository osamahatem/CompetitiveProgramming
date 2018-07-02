/*
 * 979D. Kuro and GCD and XOR and SUM.cpp
 *
 *  Created on: Jun 30, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/59462
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int LOGN = 17;
const int SZ = MAXN * LOGN * LOGN;

int head[MAXN], nxt[SZ][2], mini[SZ], cnt;
bool vis[MAXN];

void insert(int root, int x) {
	for (int i = LOGN - 1; ~i; i--) {
		int bit = (x >> i) & 1;
		if (nxt[root][bit] == -1)
			nxt[root][bit] = ++cnt;
		root = nxt[root][bit];
		mini[root] = min(mini[root], x);
	}
}

int solve(int root, int x, int lim) {
	int ret = 0;
	for (int i = LOGN - 1; ~i; i--) {
		int bit = ((x >> i) & 1) ^ 1;
		if (nxt[root][bit] != -1 && mini[nxt[root][bit]] <= lim)
			root = nxt[root][bit], ret |= bit << i;
		else if (nxt[root][bit ^ 1] != -1 && mini[nxt[root][bit ^ 1]] <= lim)
			root = nxt[root][bit ^ 1], ret |= (bit ^ 1) << i;
		else
			return -1;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	memset(nxt, -1, sizeof nxt);
	memset(mini, 127, sizeof mini);
	for (int i = 1; i < MAXN; i++)
		head[i] = ++cnt;

	int q;
	cin >> q;
	while (q--) {
		int t, x, k, s;
		cin >> t >> x;
		if (t == 1) {
			if (vis[x])
				continue;
			vis[x] = true;

			for (int i = 1; i * i <= x; i++) {
				if (x % i)
					continue;
				insert(i, x);
				if (x / i != i)
					insert(x / i, x);
			}
		} else {
			cin >> k >> s;
			if (x % k) {
				cout << -1 << endl;
				continue;
			}
			cout << solve(k, x, s - x) << endl;
		}
	}
	return 0;
}
