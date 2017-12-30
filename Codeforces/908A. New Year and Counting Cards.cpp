/*
 * 908A. New Year and Counting Cards.cpp
 *
 *  Created on: Dec 29, 2017
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56713
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const string let = "aeiou13579";

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < (int) s.size(); i++)
		if (let.find(s[i]) != string::npos)
			ans++;
	cout << ans << endl;
	return 0;
}
