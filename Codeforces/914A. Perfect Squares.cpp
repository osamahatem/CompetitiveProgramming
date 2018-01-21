/*
 * 914A. Perfect Squares.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/57250
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool sq[1000005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i <= 1000; i++)
		sq[i * i] = 1;
	int n, x, ans = -(1e9);
	cin >> n;
	while (n--) {
		cin >> x;
		if (x < 0 || !sq[x])
			ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}
