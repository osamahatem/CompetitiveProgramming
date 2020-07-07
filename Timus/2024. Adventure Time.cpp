/*
 * 2024. Adventure Time.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[26], dp[26][26], k;
vector<int> all;

int cntWays(int cur, int least) {
	if (cur == k || cur == (int) all.size())
		return 1;
	if (least == (int) all.size())
		return 0;
	int &ret = dp[cur][least];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = least; i < (int) all.size(); i++)
		if (all[i] == all[cur])
			ret += cntWays(cur + 1, i + 1);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	string in;
	cin >> in >> k;
	for (int i = 0; i < (int) in.size(); i++)
		cnt[in[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		if (cnt[i])
			all.push_back(cnt[i]);
	sort(all.begin(), all.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < min(k, (int) all.size()); i++)
		ans += all[i];
	int ways = cntWays(0, 0);
	cout << ans << " " << ways << endl;
	return 0;
}
