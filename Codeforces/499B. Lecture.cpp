/*
 * 499B. Lecture.cpp
 *
 *  Created on: Dec 24, 2014
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

	int m, n;
	string a, b, w;
	map<string, string> dic;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		dic[a] = b;
	}
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cin >> w;
		if (dic[w].size() < w.size())
			cout << dic[w];
		else
			cout << w;
	}
	cout << endl;
	return 0;
}
