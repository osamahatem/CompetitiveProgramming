/*
 * 496B. Secret Combination.cpp
 *
 *  Created on: Dec 17, 2014
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

	int len;
	string in, str, ans;
	cin >> len >> in;
	for (int i = 0; i < len; i++)
		ans += "9";
	str = in + in;
	for (int i = 0; i < 10; i++) {
		for (int s = 0; s < len; s++) {
			string temp = str.substr(s, len);
			ans = min(temp, ans);
		}
		for (int s = 0; s < 2 * len; s++)
			str[s] = (str[s] == '9' ? '0' : str[s] + 1);
	}
	cout << ans << endl;
	return 0;
}
