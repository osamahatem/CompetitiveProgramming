/*
 * 501B. Misha and Changing Handles.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int q;
	string o, n;
	cin >> q;
	map<string, string> names;
	while (q--) {
		cin >> o >> n;
		if (names.count(o)) {
			string t = names[o];
			names.erase(names.find(o));
			names[n] = t;
		} else
			names[n] = o;
	}
	cout << names.size() << endl;
	for (map<string, string>::iterator it = names.begin(); it != names.end();
			it++)
		cout << it->second << " " << it->first << endl;
	return 0;
}
