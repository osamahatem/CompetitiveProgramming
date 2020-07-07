/*
 * 394C. Dominoes.cpp
 *
 *  Created on: May 8, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[3], sum[2005], lim[1005];
string ans[1005][1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	string s;
	map<string, int> toInt;
	toInt["00"] = 0, toInt["01"] = toInt["10"] = 1, toInt["11"] = 2;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			ans[i][j] = "00";
			cin >> s;
			cnt[toInt[s]]++;
		}
	int col = 0;
	while (cnt[2]) {
		cnt[2]--;
		ans[lim[col]][col] = "11";
		lim[col]++;
		col = (col + 1) % m;
	}
	while (cnt[1]) {
		if (lim[col] + 1 < n && cnt[1] > 1) {
			cnt[1] -= 2;
			ans[lim[col]][col] = "10";
			ans[lim[col] + 1][col] = "01";
			lim[col] += 2;
		} else {
			cnt[1]--;
			ans[lim[col]][col] = "10";
			lim[col]++;
		}
		col = (col + 1) % m;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j)
				cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
