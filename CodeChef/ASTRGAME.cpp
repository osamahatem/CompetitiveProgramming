/*
 * ASTRGAME.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, dp[31][31];
string str;
vector<string> dict;

int solve(int s, int e) {
	int &ret = dp[s][e];
	if (ret != -1)
		return ret;
	set<int> S;
	for (int i = s; i < e; i++)
		for (int j = 0; j < n; j++)
			if (i + (int) dict[j].size() <= e
					&& dict[j] == str.substr(i, dict[j].size())) {
				int x = 0;
				if (i > s)
					x ^= solve(s, i);
				if (i + (int) dict[j].size() < e)
					x ^= solve(i + dict[j].size(), e);
				S.insert(x);
			}
	ret = 0;
	while (S.count(ret))
		ret++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	while (T--) {
		cin >> str >> n;
		dict.resize(n);
		for (int i = 0; i < n; i++)
			cin >> dict[i];
		memset(dp, -1, sizeof dp);
		cout << (solve(0, str.size()) ? "Teddy" : "Tracy") << endl;
	}
	return 0;
}
