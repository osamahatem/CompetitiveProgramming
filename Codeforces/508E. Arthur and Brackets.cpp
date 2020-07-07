/*
 * 508E. Arthur and Brackets.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool dp[605][1205], vis[605][1205];
int n, l[605], r[605], path[605][1205];
char out[1205];

bool solve(int idx, int len) {
	if (idx == n || len == 0)
		return true;
	if (vis[idx][len])
		return dp[idx][len];
	vis[idx][len] = 1;
	bool &ret = dp[idx][len] = false;
	for (int i = l[idx]; i <= r[idx] && i < len; i += 2) {
		bool temp = solve(idx + 1, i - 1)
				&& solve(idx + (i - 1) / 2 + 1, len - i - 1);
		if (temp) {
			ret = true;
			path[idx][len] = i;
			break;
		}
	}
	return ret;
}

void build(int idx, int len, int c) {
	if (idx == n || len == 0)
		return;
	int ch = path[idx][len];
	out[c] = '(', out[c + ch] = ')';
	build(idx + 1, ch - 1, c + 1);
	build(idx + (ch - 1) / 2 + 1, len - ch - 1, c + ch + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	out[n * 2] = '\0';
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		if (l[i] % 2 == 0)
			l[i]++;
		if (r[i] % 2 == 0)
			r[i]--;
	}
	bool ans = solve(0, n * 2);
	if (!ans) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	build(0, n * 2, 0);
	cout << out << endl;
	return 0;
}
