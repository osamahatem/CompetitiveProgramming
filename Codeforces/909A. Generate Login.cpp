/*
 * 909A. Generate Login.cpp
 *
 *  Created on: Dec 27, 2017
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56666
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string a, b;
	cin >> a >> b;
	string ans = "";
	ans += a[0];
	for (int i = 1; i < (int) a.size() && a[i] < b[0]; i++)
		ans += a[i];
	ans += b[0];
	cout << ans << endl;
	return 0;
}
