/*
 * 54D. Writing a Song.cpp
 *
 *  Created on: Aug 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k, fail[105], path[105][105];
string S, pos;
bool vis[105][105], dp[105][105];

void computeFail() {
	fail[0] = 0;
	int len = 0;
	for (int i = 1; S[i]; i++) {
		while (len && S[len] != S[i])
			len = fail[len - 1];
		if (S[len] == S[i])
			len++;
		fail[i] = len;
	}
}

bool solve(int idx, int mch) {
	if (idx == n)
		return true;
	if (vis[idx][mch])
		return dp[idx][mch];
	vis[idx][mch] = 1;
	for (int i = 0; i < k; i++) {
		int nm = mch;
		while (nm && S[nm] != i + 'a')
			nm = fail[nm - 1];
		if (S[nm] == i + 'a')
			nm++;
		if (pos[idx - (int) S.size() + 1] == '1' && S[nm])
			continue;
		if (!S[nm]) {
			if (pos[idx - nm + 1] != '1')
				continue;
			else
				nm = fail[nm - 1];
		}
		if (solve(idx + 1, nm)) {
			path[idx][mch] = i;
			dp[idx][mch] = true;
			break;
		}
	}
	return dp[idx][mch];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string ans;
	cin >> n >> k >> S >> pos;
	computeFail();
	if (solve(0, 0)) {
		int m = 0;
		for (int i = 0; i < n; i++) {
			if (m == (int) S.size())
				m = (m ? fail[m - 1] : 0);
			ans += path[i][m] + 'a';
			int p = path[i][m];
			while (m && S[m] != p + 'a')
				m = fail[m - 1];
			if (S[m] == p + 'a')
				m++;
		}
		cout << ans << endl;
	} else
		cout << "No solution" << endl;
	return 0;
}
