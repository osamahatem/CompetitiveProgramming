/*
 * 913A. Modular Exponentiation.cpp
 *
 *  Created on: Jan 8, 2018
 *      Author: Osama Hatem
 */

/*
http://codeforces.com/blog/entry/56992
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int p = 1;
	while (n && p <= m)
		p <<= 1, n--;
	if (n == 0)
		cout << m % p << endl;
	else
		cout << m << endl;
	return 0;
}
