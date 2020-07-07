/*
 * 190C. STL.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string ans;
bool flag;

void solve() {
	string word;
	if (!(cin >> word)) {
		flag = 1;
		return;
	}
	ans += word;
	if (word == "pair") {
		ans += '<';
		solve();
		ans += ',';
		solve();
		ans += '>';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	string word;
	cin >> n;
	solve();
	if (flag || cin >> word)
		ans = "Error occurred";
	cout << ans << endl;
	return 0;
}
