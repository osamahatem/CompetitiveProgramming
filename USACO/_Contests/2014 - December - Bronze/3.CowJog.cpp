/*
 * 3.CowJog.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
//#endif

	int n, x, sp[100005], ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x >> sp[i];
	for (int i = n - 1; i >= 0; i--) {
		int j = i - 1;
		while (j >= 0 && sp[j] > sp[i])
			j--;
		ans++;
		i = j + 1;
	}
	cout << ans << endl;
	return 0;
}
