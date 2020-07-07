/*
 * G. Sphenic numbers.cpp
 *
 *  Created on: Oct 19, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool prime[1 << 24];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, cnt = 0;
	cin >> n;
	for (int i = 2; i <= n && n > 1; i++) {
		if (!prime[i]) {
			for (int j = i; j <= n; j += i)
				prime[j] = 1;
			if (n % i == 0)
				n /= i, cnt++;
		}
	}
	cout << (cnt == 3 && n == 1 ? "YES" : "NO") << endl;
	return 0;
}
