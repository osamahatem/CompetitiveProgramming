/*
 ID: 19semse1
 PROG: fact4
 LANG: C++
 */
/*
 * fact4.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
//#endif

	int n, ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		while (ans % 10 == 0)
			ans /= 10;
		ans %= 1000000;
	}
	cout << ans % 10 << endl;
	return 0;
}
