/*
 * 461B. Appleman and Tree.cpp
 *
 *  Created on: Aug 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1000000007;

int head[MAXN], to[2 * MAXN], nxt[2 * MAXN], last;
int black[MAXN], par[MAXN];
bool isBlack[MAXN], leaf[MAXN];
long long dp[MAXN][2];

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t) {
	addEdge(f, t);
	addEdge(t, f);
}

void dfs(int n) {
	int ch = 0;
	for (int i = head[n]; i != -1; i = nxt[i]) {
		if (to[i] == par[n])
			continue;
		ch++;
		par[to[i]] = n;
		dfs(to[i]);
		black[n] += black[to[i]];
	}
	black[n] += isBlack[n];
	leaf[n] = ch == 0;
}

long long fastPower(long long b, long long p) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % MOD;
		b = b * b % MOD;
	}
	return ret;
}

long long solve(int n, bool sep) {
	if (isBlack[n] && sep)
		return 0;
	if (leaf[n])
		return 1;
	if (dp[n][sep] != -1)
		return dp[n][sep];
	if (isBlack[n])
		sep = 1;
	long long ret = 0;
	if (black[n] && !sep) {
		long long temp = 1;
		for (int i = head[n]; i != -1; i = nxt[i])
			if (to[i] != par[n] && black[to[i]]) {
				long long tt = (solve(to[i], 1) + solve(to[i], 0)) % MOD;
				temp = temp * tt % MOD;
			}
		for (int i = head[n]; i != -1; i = nxt[i])
			if (to[i] != par[n] && black[to[i]]) {
				long long tt = (solve(to[i], 1) + solve(to[i], 0)) % MOD;
				tt = temp * fastPower(tt, MOD - 2) % MOD;
				ret = (ret + tt * solve(to[i], 0)) % MOD;
			}
	} else {
		ret = 1;
		for (int i = head[n]; i != -1; i = nxt[i]) {
			if (to[i] == par[n])
				continue;
			long long t2 = solve(to[i], black[to[i]] ? sep : 0);
			if (black[to[i]] && sep)
				t2 = (t2 + solve(to[i], 0)) % MOD;
			ret = ret * t2 % MOD;
		}
	}
	return dp[n][sep] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	memset(dp, -1, sizeof dp);
	int n, p;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> p;
		addBiEdge(i, p);
	}
	for (int i = 0; i < n; i++)
		cin >> isBlack[i];
	par[0] = -1;
	dfs(0);
	cout << solve(0, 0) << endl;
	return 0;
}
