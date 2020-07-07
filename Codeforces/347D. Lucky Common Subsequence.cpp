/*
 * 347D. Lucky Common Subsequence.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int INF = 300;

string s1, s2, v;
int match[105][26], dp[105][105][105], path[105][105][105];

int solve(int i1, int i2, int iv) {
	if (i1 == (int) s1.size() || i2 == (int) s2.size())
		return 0;
	int &ret = dp[i1][i2][iv];
	if (ret != -1)
		return ret;
	ret = solve(i1 + 1, i2, iv);
	path[i1][i2][iv] = 0;
	int temp = solve(i1, i2 + 1, iv);
	if (temp > ret)
		ret = temp, path[i1][i2][iv] = 1;
	if (s1[i1] == s2[i2] && match[iv][s1[i1] - 'A'] != (int) v.size()) {
		temp = 1 + solve(i1 + 1, i2 + 1, match[iv][s1[i1] - 'A']);
		if (temp > ret)
			ret = temp, path[i1][i2][iv] = 2;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(match, 0, sizeof match);
	memset(dp, -1, sizeof dp);
	cin >> s1 >> s2 >> v;
	for (int i = 0; i < (int) v.size(); i++) {
		string cur = v.substr(0, i);
		for (int c = 0; c < 26; c++) {
			string temp = cur + (char) (c + 'A');
			for (int j = i; j >= 0; j--) {
				bool flag = 1;
				for (int k = 0; k + j <= i; k++)
					if (temp[k + j] != v[k])
						flag = 0;
				if (flag)
					match[i][c] = i - j + 1;
			}
		}
	}
	int ans = solve(0, 0, 0);
	int i1 = 0, i2 = 0, iv = 0;
	while (i1 < (int) s1.size() && i2 < (int) s2.size()) {
		if (path[i1][i2][iv] == 0)
			i1++;
		else if (path[i1][i2][iv] == 1)
			i2++;
		else {
			cout << s1[i1];
			iv = match[iv][s1[i1] - 'A'];
			i1++, i2++;
		}
	}
	if (ans == 0)
		cout << ans;
	cout << endl;
	return 0;
}
