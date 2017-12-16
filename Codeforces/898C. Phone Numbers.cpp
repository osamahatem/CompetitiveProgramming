/*
 * 898C. Phone Numbers.cpp
 *
 *  Created on: Dec 16, 2017
 *      Author: Osama Hatem
 */
 
/*
Simple implementation problem. Just follow steps in statement. Use map to merge
records of same user.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<string, vector<string>> all;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--) {
		string name;
		int k;
		cin >> name >> k;
		while (k--) {
			string temp;
			cin >> temp;
			all[name].push_back(temp);
		}
	}
	cout << all.size() << endl;
	for (auto p : all) {
		set<string> out;
		for (auto s : p.second) {
			bool flag = true;
			for (auto ss : p.second) {
				if (ss.size() <= s.size())
					continue;
				if (ss.substr(ss.size() - s.size(), s.size()) == s)
					flag = false;
			}
			if (flag)
				out.insert(s);
		}
		cout << p.first << " " << out.size();
		for (auto s : out)
			cout << " " << s;
		cout << endl;
	}
	return 0;
}
