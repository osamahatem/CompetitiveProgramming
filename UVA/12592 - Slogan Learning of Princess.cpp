/*
 * 12592 - Slogan Learning of Princess.cpp
 *
 *  Created on: Aug 19, 2014
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

	int n, q;
	string temp;
	cin >> n;
	vector<pair<string, string> > slo(n);
	getline(cin, temp);
	for (int i = 0; i < n; i++) {
		getline(cin, slo[i].first);
		getline(cin, slo[i].second);
	}
	cin >> q;
	getline(cin, temp);
	while (q--) {
		getline(cin, temp);
		for (int i = 0; i < n; i++) {
			if (temp == slo[i].first) {
				cout << slo[i].second << "\n";
				break;
			}
		}
	}
	return 0;
}
