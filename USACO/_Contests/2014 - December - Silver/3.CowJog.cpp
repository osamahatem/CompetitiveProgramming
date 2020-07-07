/*
 * 3.CowJog.cpp
 *
 *  Created on: Dec 15, 2014
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

	int n, ans = 0, s, v;
	long long t, final[100005];
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> s >> v;
		final[i] = t * v + s;
	}
	for (int i = n - 1; i >= 0; i--) {
		int j = i - 1;
		while (j >= 0 && final[j] >= final[i])
			j--;
		ans++;
		i = j + 1;
	}
	cout << ans << endl;
	return 0;
}
