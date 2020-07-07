/*
 * 538A. Cutting Banner.cpp
 *
 *  Created on: Apr 26, 2015
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

	string in, tar = "CODEFORCES";
	cin >> in;
	int len = (int) in.size();
	for (int i = 0; i <= len; i++)
		for (int j = i; j <= len; j++)
			if (in.substr(0, i) + in.substr(j, len - j) == tar) {
				cout << "YES" << endl;
				return 0;
			}
	cout << "NO" << endl;
	return 0;
}
