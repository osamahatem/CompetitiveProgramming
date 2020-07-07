/*
 * 7094 - Happy Happy Prime Prime.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[10005];

bool isPrime(int x) {
	if (x == 1)
		return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

bool isHappy(int x) {
	memset(vis, 0, sizeof vis);
	while (!vis[x]) {
		vis[x] = 1;
		int temp = 0;
		while (x) {
			temp += (x % 10) * (x % 10);
			x /= 10;
		}
		x = temp;
		if (x == 1)
			return true;
	}
	return false;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	int T;
	cin >> T;
	while (T--) {
		int t, n;
		cin >> t >> n;
		cout << t << " " << n << " "
				<< (isPrime(n) && isHappy(n) ? "YES" : "NO") << endl;
	}
	return 0;
}
