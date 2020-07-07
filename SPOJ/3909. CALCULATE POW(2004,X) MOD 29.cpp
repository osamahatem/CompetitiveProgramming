/*
 * 3909. CALCULATE POW(2004,X) MOD 29.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 29;

vector<pair<int, int> > fact;

void init() {
	int x = 2004;
	for (int i = 2; i * i <= x; i++) {
		int c = 0;
		while (x % i == 0) {
			c++;
			x /= i;
		}
		if (c)
			fact.push_back(make_pair(i, c));
	}
	if (x > 1)
		fact.push_back(make_pair(x, 1));
}

int fastPower(int b, int p) {
	int ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % MOD;
		b = b * b % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	init();
	int x;
	while (cin >> x, x) {
		int ans = 1;
		for (int i = 0; i < (int) fact.size(); i++) {
			int temp = fastPower(fact[i].first, fact[i].second * x + 1);
			temp = (temp - 1 + MOD) % MOD;
			temp = temp * fastPower(fact[i].first - 1, MOD - 2) % MOD;
			ans = ans * temp % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
