/*
 * K. String Stretching.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string s, ans, p;
int dp[201][201][2];

int solve(int si, int pi, bool inception) {
	if (si > (int) s.size())
		return 0;
	if (si == (int) s.size())
		return (pi == (int) p.size() ? si : 0);
	if (pi == (int) p.size() && inception)
		return si;
	pi %= p.size();
	int& ret = dp[si][pi][inception];
	if (~ret)
		return ret;
	ret = 0;
	if (s[si] == p[pi])
		ret = solve(si + 1, pi + 1, inception);
	if (pi && s[si] == p[0])
		ret = max(ret, solve(solve(si + 1, 1, 1), pi, inception));
	return ret;
}

bool cmp(string a, string b) {
	return a.size() < b.size() || (a.size() == b.size() && a < b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> s;
	ans = s;
	for (int i = 1; i < (int) s.size(); i++) {
		if (s.size() % i)
			continue;
		for (int j = 0; j + i <= (int) s.size(); j++) {
			p = s.substr(j, i);
			memset(dp, -1, sizeof dp);
			if (cmp(p, ans) && solve(0, 0, 0) == (int) s.size())
				ans = p;
		}
	}
	cout << ans << endl;
	return 0;
}
