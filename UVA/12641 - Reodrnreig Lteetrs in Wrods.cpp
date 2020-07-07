/*
 * 12641 - Reodrnreig Lteetrs in Wrods.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool check(string a, string b) {
	int cnt[26];
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < (int) a.size(); i++)
		cnt[a[i] - 'a']++;
	for (int i = 0; i < (int) b.size(); i++)
		cnt[b[i] - 'a']--;
	for (int i = 0; i < 26; i++)
		if (cnt[i] != 0)
			return false;
	return (a[0] == b[0] && a[a.size() - 1] == b[b.size() - 1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	scanf("%d ", &t);
	while (t--) {
		vector<string> dic;
		string s;
		stringstream ss;
		getline(cin, s);
		ss << s;
		while (ss >> s)
			dic.push_back(s);
		sort(dic.begin(), dic.end());
		ss.clear();
		getline(cin, s);
		ss << s;
		bool first = 1;
		while (ss >> s) {
			if (!first)
				cout << " ";
			for (int i = 0; i < (int) dic.size(); i++) {
				if (check(dic[i], s)) {
					cout << dic[i];
					break;
				}
				if (i + 1 == (int) dic.size())
					cout << s;
			}
			first = 0;
		}
		cout << "\n";
	}
	return 0;
}
