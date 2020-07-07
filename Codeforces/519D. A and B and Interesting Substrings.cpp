/*
 * 519D. A and B and Interesting Substrings.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int val[26];
map<pair<char, long long>, int> cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string s;
	long long sum = 0, ans = 0;
	for (int i = 0; i < 26; i++)
		cin >> val[i];
	cin >> s;
	for (int i = 0; i + 1 < (int) s.size(); i++) {
		sum += val[s[i] - 'a'];
		cnt[make_pair(s[i + 1], sum)]++;
	}
	sum = 0;
	for (int i = 0; i + 1 < (int) s.size(); i++) {
		sum += val[s[i] - 'a'];
		ans += cnt[make_pair(s[i], sum)];
		cnt[make_pair(s[i + 1], sum)]--;
	}
	cout << ans << endl;
	return 0;
}
