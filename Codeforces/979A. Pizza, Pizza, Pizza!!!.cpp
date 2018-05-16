/*
 * 979A. Pizza, Pizza, Pizza!!!.cpp
 *
 *  Created on: May 14, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/59462
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	long long n;
	cin >> n;
	n++;
	long long ans = (n & 1 ? n : n / 2);
	if (n == 1)
		ans = 0;
	cout << ans << endl;
	return 0;
}
