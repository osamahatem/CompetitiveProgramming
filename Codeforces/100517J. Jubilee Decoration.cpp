/*
 * J. Jubilee Decoration.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: Osama Hatem
 */
 
/*
The general solution uses only 3 types: alternate roads to the capital between
two types, one for odd numbered cities and one for even, and a third type for
the outer ring. If two cities have different parities, we can go through the
capital, otherwise we take one road on the outer ring and then go through the
capital.
There are two special cases:
	- 3 cities: distance between any two nodes is 1, only one type is needed.
	- 4-6 cities: by alternating both the outer ring roads, and the capital
		roads, based on parity, all trips can be achieved with two different
		types of edges.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("jubilee.in", "r", stdin);
	freopen("jubilee.out", "w", stdout);

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n, n) {
		if (n < 4) {
			cout << "1\n";
			for (int i = 0; i < n; i++)
				cout << "1" << " \n"[i == n - 1];
			for (int i = 0; i < n; i++)
				cout << "1" << " \n"[i == n - 1];
		} else if (n < 7) {
			cout << "2\n";
			for (int i = 0; i < n; i++)
				cout << "12"[i & 1] << " \n"[i == n - 1];
			for (int i = 0; i < n; i++)
				cout << "12"[i & 1] << " \n"[i == n - 1];
		} else {
			cout << "3\n";
			for (int i = 0; i < n; i++)
				cout << "12"[i & 1] << " \n"[i == n - 1];
			for (int i = 0; i < n; i++)
				cout << "3" << " \n"[i == n - 1];
		}
	}
	return 0;
}
