/*
 * WORDCNT.cpp
 *
 *  Created on: May 13, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<int> getLengths(string line) {
	vector<int> ret;
	int cnt = 0;
	for (int i = 0; i < (int) line.size(); i++) {
		if (line[i] >= 'a' && line[i] <= 'z') {
			cnt++;
		} else if (cnt) {
			ret.push_back(cnt);
			cnt = 0;
		}
	}
	if (cnt)
		ret.push_back(cnt);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	string in;
	cin >> T;
	getline(cin, in);
	while (T--) {
		getline(cin, in);
		vector<int> lens = getLengths(in);
		int maxi = 1, temp = 1;
		for (int i = 1; i < (int) lens.size(); i++) {
			if (lens[i] == lens[i - 1])
				temp++;
			else
				temp = 1;
			maxi = max(maxi, temp);
		}
		cout << maxi << endl;
	}
	return 0;
}
