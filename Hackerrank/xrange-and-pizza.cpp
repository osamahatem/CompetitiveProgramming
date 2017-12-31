/*
 * xrange-and-pizza.cpp
 *
 *  Created on: Dec 31, 2017
 *      Author: Osama Hatem
 */
 
/*
Flipping around an axis is equivalent to a rotation with k = axis number, after
switching directions.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int cur = 0, dir = 1;
	while (m--) {
		int t, k;
		cin >> t >> k;
		if (t == 2)
			dir *= -1;
		cur = (cur + k * dir + n) % n;
	}
	cout << (dir == 1 ? "1 " : "2 ") << (n - cur) % n << endl;
	return 0;
}
