/*
 * 898B. Proper Nutrition.cpp
 *
 *  Created on: Dec 16, 2017
 *      Author: Osama Hatem
 */
 
/*
Try all amounts of the first product, check if second can add up to n.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, b;
	cin >> n >> a >> b;
	for (int x = 0; x * a <= n; x++) {
		if ((n - x * a) % b)
			continue;
		int y = (n - x * a) / b;
		cout << "YES\n" << x << " " << y << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
