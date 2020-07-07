/*
 * D. Dragon’s Question.cpp
 *
 *  Created on: Oct 7, 2017
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

	freopen("dragon.in", "r", stdin);
	freopen("dragon.out", "w", stdout);

	int n, d;
	cin >> n >> d;
	string ans = "";
	while (d) {
		ans += '0' + d % 10;
		d /= 10;
	}
	reverse(ans.begin(), ans.end());
	while ((int) ans.size() < n)
		ans += "0";
	cout << ((int) ans.size() > n ? "No solution" : ans) << endl;
	return 0;
}
