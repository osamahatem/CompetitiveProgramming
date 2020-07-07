/*
 * 255B. Code Parsing.cpp
 *
 *  Created on: Aug 30, 2015
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

	string S, ans;
	cin >> S;
	int x = count(S.begin(), S.end(), 'x'), y = count(S.begin(), S.end(), 'y');
	char z = 'x';
	if (y > x)
		z = 'y';
	for (int i = 0; i < abs(x - y); i++)
		ans += z;
	cout << ans << endl;
	return 0;
}
