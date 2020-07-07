/*
 * 102C. Homework.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char str[100005];
bool vis[100005];
vector<pair<int, char>> cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int k, let = 26;
	scanf("%s%d", str, &k);
	for (int i = 0; i < 26; i++)
		cnt.push_back(make_pair(0, 'a' + i));
	for (int i = 0; str[i]; i++)
		cnt[str[i] - 'a'].first++;
	sort(cnt.begin(), cnt.end());
	for (int i = 0; i < 26; i++) {
		if (k < cnt[i].first)
			break;
		k -= cnt[i].first, let--;
		for (int j = 0; str[j]; j++)
			vis[j] |= str[j] == cnt[i].second;
	}
	string ans = "";
	for (int j = 0; str[j]; j++)
		if (!vis[j])
			ans += str[j];
	printf("%d\n%s\n", let, ans.c_str());
	return 0;
}
