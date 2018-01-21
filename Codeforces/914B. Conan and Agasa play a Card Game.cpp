/*
 * 914B. Conan and Agasa play a Card Game.cpp
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

int cnt[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, x;
	int ans = 0;
	cin >> n;
	while (n--) {
		cin >> x;
		cnt[x]++;
		if (cnt[x] & 1)
			ans++;
		else
			ans--;
	}
	cout << (ans ? "Conan" : "Agasa") << endl;
	return 0;
}
