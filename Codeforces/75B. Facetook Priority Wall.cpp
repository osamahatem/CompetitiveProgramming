/*
 * 75B. Facetook Priority Wall.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct frnd {
	string name;
	int val;

	const bool operator <(const frnd &other) const {
		if (val != other.val)
			return val > other.val;
		return name < other.name;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string name, n1, n2, act, ex;
	int n;
	map<string, int> pri;
	map<string, int>::iterator it;
	cin >> name >> n;
	while (n--) {
		cin >> n1 >> act;
		if (act != "likes")
			cin >> ex;
		cin >> n2 >> ex;
		n2 = n2.substr(0, n2.size() - 2);
		pri[n1], pri[n2];
		if (n1 != name && n2 != name)
			continue;
		if (n2 == name)
			swap(n1, n2);
		pri[n2] += (act == "posted" ? 15 : (act == "likes" ? 5 : 10));
	}
	vector<frnd> all;
	for (it = pri.begin(); it != pri.end(); it++) {
		if (it->first == name)
			continue;
		all.push_back(frnd { it->first, it->second });
	}
	sort(all.begin(), all.end());
	for (int i = 0; i < (int) all.size(); i++)
		cout << all[i].name << endl;
	return 0;
}
